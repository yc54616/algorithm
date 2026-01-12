#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	scanf("%d", &n);
	int *cards = (int*)calloc(n, sizeof(int));
	for(int i = 0; i < n; i++){
		int card;
		scanf("%d", &card);
		cards[card-1] = 1;
	}
	for(int i = 0; i < n; i++){
		if(cards[i] == 0){
			printf("%d\n", i+1);
		}
	}
	free(cards);
	return 0;
}
