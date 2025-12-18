#include <stdio.h>

void f(int a, int b){
	if(a > b)
		return;
	f(a, b-1);
	if(b % 2)
		printf("%d ", b);
}

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	f(a, b);
}
