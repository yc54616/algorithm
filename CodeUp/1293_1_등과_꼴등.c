#include <stdio.h>

int main(){
	int n, k;
	int max = 0, min = 10000;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &k);
		if(min > k){
			min = k;
		}
		if(max < k){
			max = k;
		}
	}
	printf("%d %d\n", max, min);
	return 0;
}
