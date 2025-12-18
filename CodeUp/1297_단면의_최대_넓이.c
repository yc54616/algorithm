#include <stdio.h>

int main(){
	int n, max = 0, max_i = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		if((n - i*2)*i > max) {
			max = (n - i*2)*i;
			max_i = i;
		}
		else break;
	}
	printf("%d\n", max_i);

	return 0;
}
