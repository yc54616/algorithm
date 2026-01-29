#include <stdio.h>

int main(){
	int k, n;
	scanf("%d %d", &k, &n);
	int sum = 0;
	int map[k+1][k+1];
	for(int i = 1; i <= k; i++){
		for(int j = 1; j <= k; j++){
			scanf("%d", &map[i][j]);

			if(map[i][j] >= 0)
				map[i][j] += n;

			if(map[i][j] >= 0 && map[i][j] <= 5){
				sum++;
			}
		}
	}

	printf("%d\n", sum);

	return 0;
}
