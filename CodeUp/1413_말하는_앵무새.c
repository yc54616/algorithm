#include <stdio.h>

int main(){
	char c[100] = {0,};
	scanf("%[^\n]s", c);
	for(int i = 99; i >= 0; i--){
		if(c[i]){
			printf("%c", c[i]);
		}
	}

	return 0;
}
