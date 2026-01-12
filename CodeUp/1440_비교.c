#include <stdio.h>
#include <stdlib.h>
int main(){
	int n;
	scanf("%d", &n);
	int* arr = (int*)malloc(n * sizeof(int));
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	
	for(int i = 0; i < n; i++){
		printf("%d: ", i+1);
		for(int j = 0; j < n; j++){
			if(i == j) continue;
			if(arr[i] == arr[j]){
				printf("= ");
			}
			else if(arr[i] < arr[j]){
				printf("< ");
			}
			else{
				printf("> ");
			}
		}	
		printf("\n");
	}
	return 0;
}
