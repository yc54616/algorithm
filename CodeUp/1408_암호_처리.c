#include <stdio.h>
#include <stdlib.h>

int main(){
	char* str = (char*)malloc(sizeof(char) * 21);
	char* str2 = (char*)malloc(sizeof(char) * 21);
	scanf("%s", str);
	memcpy(str2, str, 21);
	for(int i = 0; str[i] != '\0'; i++){
		str[i] = str[i] + 2;
	}
	for(int i = 0; str[i] != '\0'; i++){
		str2[i] = (str2[i] * 7) % 80 + 48;
	}
	printf("%s\n", str);
	printf("%s\n", str2);
	free(str);
	free(str2);
	return 0;
}
