#include <stdio.h>

// 
// 10
// 9 8
// 7 6 5
// 4 3 2 1

int main(){
	int n;
	scanf("%d", &n);
	int num = n * (n + 1) / 2;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= i; j++){
			printf("%d ", num--);
		}
		printf("\n");
	}

	return 0;
}
