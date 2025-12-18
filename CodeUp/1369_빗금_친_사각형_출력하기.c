#include <stdio.h>

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++){
		if(i == 1 || i == n){
			for(int j = 0; j < n; j++){
				printf("*");
			}
		}
		else{
			printf("*");
			for(int j = 1; j <= n - 2; j++){
				if((i+j) % k == 0){
					printf("*");
				}
				else{
					printf(" ");
				}
			}
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
