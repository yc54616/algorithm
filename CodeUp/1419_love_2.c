#include <stdio.h>

int main(){
	char c[101] = {0,};
	int count = 0;
	scanf("%[^\n]s", c);
	for(int i = 0; c[i] != '\0'; i++){
		if(c[i] == 'l' && c[i+1] == 'o' && c[i+2] == 'v' && c[i+3] == 'e'){
			count++;
		}
	}
	printf("%d", count);	

	return 0;
}
