#include <stdio.h>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int arr[n+1][m+1];
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(n % 2 == 0){
				if(i % 2) arr[i][j] = (n - i) * m + j;
				else arr[i][j] = m + (n - i) * m - j + 1;
			}	
			else{
				if(i % 2 == 0) arr[i][j] = (n - i) * m + j;
				else arr[i][j] = m + (n - i) * m - j + 1;
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
