#include <stdio.h>

int main(){
	int x;
	scanf("%d", &x);
	for(int i = x; i >= 1; i--){
		for(int j = x; j > i; j--){
			printf(" ");
		}
		for(int j = 0; j < i; j++){
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
