#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int *arr = (int *)malloc(sizeof(int) * n);
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%d ", arr[(i+j)%n]);
		}
		printf("\n");
	}
	free(arr);
	return 0;
}
