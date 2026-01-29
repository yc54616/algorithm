#include <stdio.h>

#define SIZE 25

int map[SIZE + 1][SIZE + 1][2] = {0};
int visited[SIZE + 1][SIZE + 1][8] = {0};

int main(){
	for(int i = 1; i <= SIZE; i++){
		for(int j = 1; j <= SIZE; j++){
			scanf("%1d", &map[i][j][0]);
		}
	}

	int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
	int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

	int qx[4096], qy[4096];
	int head = 0, tail = 0;


	for(int i = 1; i <= SIZE; i++){
		for(int j = 1; j <= SIZE; j++){
			qx[tail] = i;
			qy[tail] = j;
			tail++;
		}
	}
		
	while (head < tail) {
		int x = qx[head];
		int y = qy[head];
		head++;

		int sum = 0;
		for(int dir = 0; dir < 8; dir++){
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if(nx < 1 || nx > SIZE || ny < 1 || ny > SIZE){
				continue;
			}

			if(visited[nx][ny][dir]){
				continue;
			}

			visited[nx][ny][dir] = 1;

			sum += map[nx][ny][0];

		}

		if(sum == 3){
			map[x][y][1] = 1;
		} else if(sum >= 4 || sum <= 1){
			map[x][y][1] = 0;
		} else {
			map[x][y][1] = map[x][y][0];
		}
	}

	for(int i = 1; i <= SIZE; i++){
		for(int j = 1; j <= SIZE; j++){
			printf("%1d ", map[i][j][1]);
		}
		printf("\n");
	}

	return 0;
}
