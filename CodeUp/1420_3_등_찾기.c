#include <stdio.h>

typedef struct {
	char name[50];
	int score;	
} Stduent;

int main(){
	int n, first = 0, second = 0, third = 0, min = 0;
	Stduent students[50];
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%s %d", students[i].name, &students[i].score);
		if(students[i].score < students[min].score){
			min = i;
		}
	}

	first = min;
	second = min;
	third = min;
	
	for(int i = 0; i < n; i++){
		scanf("%s %d", students[i].name, &students[i].score);
		if(students[i].score > students[first].score){
			third = second;
			second = first;
			first = i;
		}
		else if(students[i].score > students[second].score){
			third = second;
			second = i;
		}
		else if(students[i].score > students[third].score){
			third = i;
		}
	}

	printf("%s", students[third].name);
	

	return 0;
}
