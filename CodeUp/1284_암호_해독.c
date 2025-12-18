#include <stdio.h>

int is_prime(int num){
	if(num < 2) return 0;
	for(int i = 2; i * i <= num; i++){
		if(num % i == 0) return 0;
	}
	return 1;
}

int divide(int a, int b){
	int result = 0;
	while (a > 0)
	{
		a -= b;
		result++;
	}
	if(a == 0) return result;
	else return -1;
}

int main(){
	int n, flag = 0;
	scanf("%d", &n);

	for(int i = 2; i < n; i++){
		if(is_prime(i) && is_prime(divide(n, i))){
			printf("%d %d\n", i, divide(n, i));
			flag = 1;
			break;
		}
	}

	if(!flag)
		puts("wrong number\n");

	return 0;
}
