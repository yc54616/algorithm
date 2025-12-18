#include <stdio.h>

int main(){
	int sum = 0, n;
	for(int i = 0; i < 10; i++){
		scanf("%1d", &n);
		sum += n;
	}

	printf("%s\n", sum - 7*(sum/7) == 4 ? "suspect" : "citizen");
	return 0;
}
