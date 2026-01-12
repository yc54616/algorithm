#include <stdio.h>

int main(){
	int k;
	scanf("%d", &k);
	int *arr = (int *)malloc(sizeof(int) * k);
	for(int i = 0; i < k; i++){
		scanf("%d", &arr[i]);
	}
	for(int j = 0; j < 2; j++){
		for(int i = 0; i < k; i++){
			printf("%d\n", arr[i]);
		}
	}
	free(arr);
	return 0;
}
