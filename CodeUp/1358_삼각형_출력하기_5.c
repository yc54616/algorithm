#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n/2 + 1; i++){
		for(int j = n/2 + 1; j > i; j--){
			printf(" ");
		}
		for(int j = 1; j <= i * 2 - 1; j++){
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
