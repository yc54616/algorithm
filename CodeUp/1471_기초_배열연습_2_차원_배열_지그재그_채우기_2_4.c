#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int arr[n+1][n+1];
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i % 2) arr[j][i] = n * i - (j - 1);
			else arr[j][i] = j + n * (i - 1);
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
