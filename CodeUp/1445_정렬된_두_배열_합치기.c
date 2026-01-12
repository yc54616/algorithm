#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b){
	return (*(int*)a - *(int*)b);
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int* result = (int*)malloc((n + m) * sizeof(int));
	for(int i = 0; i < n + m; i++){
		scanf("%d", &result[i]);
	}
	qsort(result, n + m, sizeof(int), compare);

	for(int i = 0; i < n + m; i++){
		printf("%d ", result[i]);
	}




	return 0;
}
