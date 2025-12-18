// C program to demonstrate working of 
// extended Euclidean Algorithm 
#include <stdio.h>

// Function for extended Euclidean Algorithm 
long long gcdExtended(long long a, long long b, long long *x, long long *y) {

    // Base Case 
    if (a == 0) { 
        *x = 0; 
        *y = 1; 
        return b; 
    } 

    long long x1, y1; 
    long long gcd = gcdExtended(b % a, a, &x1, &y1); 

    // Update x and y using results of 
    // recursive call 
    *x = y1 - (b / a) * x1; 
    *y = x1; 
    return gcd; 
} 
int main() { 
	long long a, b, c;
	scanf("%lld %lld %lld", &a, &b, &c);

	if (a == 0 && b == 0) {
        if (c == 0) printf("0 0\n"); // 임의의 해 (문제 조건 확인 필요)
        else printf("Not Exist\n");
        return 0;
    }

	long long x, y;
	long long g = gcdExtended(a, b, &x, &y);
	
	if (c % g != 0) {
		printf("Not Exist\n");
		return 0;
	}
	x = x * (c / g);
	y = y * (c / g);
	printf("%lld %lld\n", x, y);


    return 0; 
}