#include <stdio.h>

int main(){
	int first = 0, second = 0, third = 0;
	int arr[10] = {0,};
	for(int i = 0; i < 10; i++){
		scanf("%d", &arr[i]);
		if(arr[i] > first){
			third = second;
			second = first;
			first = arr[i];
		}
		else if(arr[i] > second){
			third = second;
			second = arr[i];
		}
		else if(arr[i] > third){
			third = arr[i];
		}
	}
	printf("%d", third);

	return 0;
}
