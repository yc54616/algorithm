#include <stdio.h>

int main(){
	int arr[10] = {0,};
	int even_max = -1, odd_max = -1;
	for(int i = 0; i < 10; i++){
		scanf("%d", &arr[i]);
	}
	
	for(int i = 0; i < 10; i++){
		if(arr[i] % 2 == 0){
			if(arr[i] > even_max){
				even_max = arr[i];
			}
		}
		else{
			if(arr[i] > odd_max){
				odd_max = arr[i];
			}
		}
	}
	if(odd_max != -1)
		printf("%d ", odd_max);
	if(even_max != -1)
		printf("%d", even_max);
		
	return 0;
}
