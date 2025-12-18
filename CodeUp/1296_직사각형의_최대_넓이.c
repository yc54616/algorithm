#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);

	int data = n;
	int data2 = n;
	int count = 0;
	while (n > 0)
	{
		n -= 4;
		count++;
	}
	
	
	data = data - count * 2;
	int count2 = 0;
	while (data > 0)
	{
		data -= 2;
		count2++;
	}

	printf("%d\n", (data2 - 2*count)/2 * count - data);
	return 0;
}