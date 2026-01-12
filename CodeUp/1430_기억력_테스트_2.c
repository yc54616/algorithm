#include <stdio.h>

int check[10000001];

int main(){
	int n, m, num;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &num);
		check[num] = 1;
	}
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%d", &num);
		printf("%d ", check[num]);
	}
	return 0;
}
