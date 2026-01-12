#include <stdio.h>

int main(){
	for(int j = 1; j <= 9; j++){
		for(int i = 2; i <= 5; i++){
			if(i == 5)
				printf("%d x %d = %2d\n", i, j, i * j);
			else
				printf("%d x %d = %2d\t", i, j, i * j);
		}
	}

	return 0;
}
