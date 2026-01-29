#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int arr[n+1][n+1];
	int x = 1, y = n/2 + 1;
	for(int i = 1; i <= n * n; i++){
		arr[x][y] = i;
		if(i % n == 0){
			x = x + 1;
		}
		else{
			x = x - 1;
			y = y + 1;
			if(x < 1) x = n;
			if(y > n) y = 1;
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
