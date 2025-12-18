#include <stdio.h>

int main(){
	int n; 
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		if(i == 0 || i == n - 1 || i == n / 2){
			for(int j = 0; j < n; j++){
				printf("*");
			}
		} else {
			printf("*");
			for(int j = 1; j <= n - 2; j++){
				if(i == j || j == n - i - 1 || j == n / 2)
					printf("*");
				else
					printf(" ");
			}
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
