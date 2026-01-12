#include <stdio.h>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int arr[n+1][m+1];
	int count = 1;
	for(int sum = 0; sum <= n + m; sum++){
		for(int j = m; j >= 1; j--){
			int i = sum - j;
			
			if(i >= 1 && i <= n){
				arr[i][m-j+1] = count++;
			}
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}
