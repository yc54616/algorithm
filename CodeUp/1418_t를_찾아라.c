#include <stdio.h>

int main(){
	char c[11] = {0,};
	scanf("%s", c);
	for(int i = 0; c[i] != '\0'; i++){
		if(c[i] == 't')
			printf("%d ", i+1);
	}
	return 0;
}
