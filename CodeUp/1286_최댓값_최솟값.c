#include <stdio.h>

int main(){
	int min, max, num;
	for(int i = 0; i < 5; i++){
		scanf("%d", &num);
		if(i == 0){
			min = num;
			max = num;
		}
		if(num < min){
			min = num;
		}
		if(num > max){
			max = num;
		}
	}

	printf("%d\n", max);
	printf("%d\n", min);
	return 0;
}