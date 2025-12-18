#include <stdio.h>

int main(){
	char c;
	while (scanf("%c", &c) != EOF)
	{
		if(c == ' ')
			printf(" ");
		else
			printf("%c", (c - 'a' + 3) % 26 + 'a');
	}
	

	return 0;
}
