#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, x, y;
	scanf("%d", &n);
	scanf("%d %d", &x, &y);
	int arr[n+1][n+1];
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			arr[i][j] = abs(i - x) + abs(j - y) + 1;
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
