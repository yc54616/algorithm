#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int arr[n+1][n+1];
	int num = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			arr[i][j] = num++;
		}
	}
	int sum = 0;
	int dx[] = {0, 1, 0, -1};
	int dy[] = {1, 0, -1, 0};
	int x = 1, y = 1, dir = 0;

	int i = 1;
	do{
		sum += arr[x][y];

		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if(nx < 1 || nx > n || ny < 1 || ny > n || arr[nx][ny] == 0){
			dir = (dir + 1) % 4;
			nx = x + dx[dir];
			ny = y + dy[dir];
		}
		x = nx;
		y = ny;
	} while (x != 1 || y != 1);

	printf("%d\n", sum);

	return 0;
}
