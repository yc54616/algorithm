#include <stdio.h>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int A[n+1][m+1], S[n+1][m+1];
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			scanf("%d", &A[i][j]);
		}
	}

	S[1][1] = A[1][1];
	for(int i = 2; i <= n; i++){
		S[i][1] = S[i-1][1] + A[i][1];
	}
	for(int i = 2; i <= m; i++){
		S[1][i] = S[1][i-1] + A[1][i];
	}
	for(int i = 2; i <= n; i++){
		for(int j = 2; j <= m; j++){
			S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + A[i][j];
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			printf("%d ", S[i][j]);
		}
		printf("\n");
	}




	return 0;
}
