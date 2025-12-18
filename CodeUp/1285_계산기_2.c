#include <stdio.h>

int main(void) {
	int num, sum = 0;
	char ch;

	scanf("%d", &sum);
	do{
		scanf("%c%d", &ch, &num);
		switch (ch)
		{
		case '+':
			sum += num;
			break;
		case '-':
			sum -= num;
			break;
		case '*':
			sum *= num;
			break;
		case '/':
			sum /= num;
			break;
		}
		
	} while (ch != '=');

	printf("%d\n", sum);
    return 0;
}