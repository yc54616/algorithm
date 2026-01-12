#include <stdio.h>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = n; i >= 1; i--){
		for(int j = m; j >= 1; j--){
			if(i % 2 == 0) printf("%d ", m * (i - 1) + j);
			else printf("%d ", (i - 1) * m + (m - j + 1));
		}
		printf("\n");
	}

	return 0;
}
