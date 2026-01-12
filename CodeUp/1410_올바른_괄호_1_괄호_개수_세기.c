#include <stdio.h>

int main(){
	int left = 0, right = 0;
	char c;
	while((c = getchar()) != EOF){
		if(c == '(') left++;
		else if(c == ')') right++;
	}
	printf("%d %d", left, right);
	return 0;
}
