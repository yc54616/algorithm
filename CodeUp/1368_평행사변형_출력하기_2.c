#include <stdio.h>

int main(){
	int h, k;
	char d;
	scanf("%d %d %c", &h, &k, &d);
	for(int i = 0; i < h; i++){
		if(d == 'L'){
			for(int j = 0; j < i; j++){
				printf(" ");
			}
		}
		else{
			for(int j = h - 1; j > i; j--){
				printf(" ");
			}
		}
		for(int j = 0; j < k; j++){
			printf("*");
		}
		printf("\n");

	}

	return 0;
}
