#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int A[n+1], S[n+1];

	for(int i = 1; i <=n; i++){
		scanf("%d", &A[i]);
	}

	S[1] = A[1];
	for(int i = 2; i <= n; i++){
		S[i] = S[i-1] + A[i];
	}

	for(int i = 1; i <= n; i++){
		printf("%d ", S[i]);
	}
	

	return 0;
}
