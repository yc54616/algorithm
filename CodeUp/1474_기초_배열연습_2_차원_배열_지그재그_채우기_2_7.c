#include <stdio.h>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int arr[n+1][m+1];
	int count = n * m;
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			if(m % 2 == 1){
				if(i % 2 == 1) arr[j][i] = count--;
				else arr[n - j + 1][i] = count--;
			}	
			else{
				if(i % 2 == 0) arr[j][i] = count--;
				else arr[n - j + 1][i] = count--;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}
