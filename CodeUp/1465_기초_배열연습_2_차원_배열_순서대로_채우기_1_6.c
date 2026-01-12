#include <stdio.h>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = n; i >= 1; i--){
		for(int j = 1; j <= m; j++){
			printf("%d ", m * (i - 1) + j);
		}
		printf("\n");
	}

	return 0;
}
