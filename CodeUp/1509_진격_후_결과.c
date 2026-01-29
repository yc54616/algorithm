#include <stdio.h>

int main(){
	int arr[11][10];
	for(int i=0;i<11;i++){
		for(int j=0;j<10;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	
	for(int j = 0; j < 10; j++){
		int flag = 0; // 0: safe, 1: crash, 2: fall
		for(int i = 0; i < 10; i++){
			if(arr[i][j] >= 1){
				flag = 1; // crash
			}
			else if(arr[i][j] < 0){
				flag = 2; // fall
			}
		}
		if(arr[10][j] == 1){
			if(flag == 1) printf("%d crash\n", j+1);
			else if(flag == 2) printf("%d fall\n", j+1);
			else printf("%d safe\n", j+1);
		}
	}

	return 0;
}
