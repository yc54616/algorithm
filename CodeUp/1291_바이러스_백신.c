#include <stdio.h>

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a % b);
}

int main(){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int result = gcd(gcd(a, b), c);
	printf("%d\n", result);
	return 0;
}
