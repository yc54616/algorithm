#include <stdio.h>

int main(){
	char c[101] = {0,};
	scanf("%[^\n]s", c);
	int c_count = 0, cc_count = 0;
	for(int i = 0; c[i] != '\0'; i++){
		if(c[i] == 'c' || c[i] == 'C'){
			c_count++;
			if(c[i+1] == 'c' || c[i+1] == 'C'){
				cc_count++;
			}
		}
	}
	printf("%d\n%d", c_count, cc_count);

	return 0;
}
