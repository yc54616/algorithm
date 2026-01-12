#include <stdio.h>
#include <stdlib.h>

int main(){
	char c[90] = {0,};
	scanf("%[^\n]s", c);
	for(int i = 'a'; i <= 'z'; i++){
		int count = 0;
		for(int j = 0; c[j] != '\0'; j++){
			if(c[j] == i) count++;
		}
		printf("%c:%d\n", i, count);
	}
	
	

	return 0;
}
