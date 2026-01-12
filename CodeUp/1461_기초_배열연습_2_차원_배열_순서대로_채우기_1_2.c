#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			printf("%d ", (n ) * i - j + 1);
		}
		printf("\n");
	}

	return 0;
}
