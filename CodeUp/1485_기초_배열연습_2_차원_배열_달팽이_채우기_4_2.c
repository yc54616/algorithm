#include <stdio.h>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int arr[n+1][m+1];
	memset(arr, 0, sizeof(arr));

	int dx[] = {0, 1, 0, -1};
	int dy[] = {1, 0, -1, 0};

	int x = 1, y = 1;
	int dir = 0;

	for(int i=n*m; i>=1; i--){
		arr[x][y] = i;
		
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if(nx < 1 || nx > n || ny < 1 || ny > m || arr[nx][ny] != 0){
			dir = (dir + 1) % 4;
			nx = x + dx[dir];
			ny = y + dy[dir];
		}
		x = nx;
		y = ny;

		
	}
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	

	return 0;
}
