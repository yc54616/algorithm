#include <stdio.h>

#define SIZE 9

int main(){
	int map[SIZE + 1][SIZE + 1];
	for(int i = 1; i <= SIZE; i++){
		for(int j = 1; j <= SIZE; j++){
			scanf("%d", &map[i][j]);
		}
	}
	int r, c;
	scanf("%d %d", &r, &c);

	if(map[r][c] == 1){
		printf("-1\n");
		return 0;
	}

	int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
	int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

	int count = 0;
	for(int i = 0; i < 8; i++){
		int nr = r + dx[i];
		int nc = c + dy[i];

		if(nr >= 1 && nr <= SIZE && nc >= 1 && nc <= SIZE && map[nr][nc] == 1){
			count++;
		}
	}
	printf("%d\n", count);

	return 0;
}
