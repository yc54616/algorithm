#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int arr[n+1][n+1];
	memset(arr, 0, sizeof(arr));

	int count = 1;
	int dir = 0; // 0: down-left, 1: up-right
	for(int sum = n + 1; sum <= n + n; sum++){
		for(int k = n; k >= 1; k--){
			int i, j;
			if(dir == 0) {
				int i = k;
				int j = sum - i;
				if(i >= 1 && i <= n && j >= 1 && j <= n && arr[i][j] == 0){
					arr[i][j] = count++;
				}
			}
			else{
				int j = k;
				int i = sum - j;
				if(i >= 1 && i <= n && j >= 1 && j <= n && arr[i][j] == 0){
					arr[i][j] = count++;
				}
			}
		}
		dir = !dir;
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}
