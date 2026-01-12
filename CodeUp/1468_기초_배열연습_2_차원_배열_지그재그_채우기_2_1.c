#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int arr[n+1][n+1];
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i % 2) arr[i][j] = j + (i - 1) * n;
			else arr[i][j] = i * n - (j - 1);
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}
