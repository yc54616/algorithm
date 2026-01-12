#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b){
	return (*(int*)a - *(int*)b);
}

int main(){
	int n, c;
	scanf("%d %d", &n, &c);
	int* arr = (int*)malloc(n * sizeof(int));
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}

	qsort(arr, n, sizeof(int), compare);

	for(int i = 0; i < n; i++){
		if((i+1) % c == 0){
			printf("%d\n", arr[i]);
		}
		else{
			printf("%d ", arr[i]);
		}
	}

	return 0;
}
