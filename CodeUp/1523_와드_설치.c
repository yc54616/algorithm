#include <stdio.h>

#define SIZE 9

int main(){
	int map[SIZE + 1][SIZE + 1] = {0};

	int a1, a2;
	scanf("%d %d", &a1, &a2);

	int b1, b2;
	scanf("%d %d", &b1, &b2);

	int c1, c2, d1, d2;
	scanf("%d %d", &c1, &c2);
	scanf("%d %d", &d1, &d2);

	int dx[] = {-2, -2, -2, -2, -2, -1, -1, -1, -1, -1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2};
	int dy[] = {-2, -1, 0, 1, 2, -2, -1, 0, 1, 2, -2, -1, 1, 2, -2, -1, 0, 1, 2, -1, 0, 1, 2, -2};

	// 렌즈
	map[b1][b2] = 2;
	for(int i = 0; i < 24; i++){
		int na1 = b1 + dx[i];
		int na2 = b2 + dy[i];

		if(na1 >= 1 && na1 <= SIZE && na2 >= 1 && na2 <= SIZE){
			map[na1][na2] = 2;
		}
	}

	if(b1 - 2 <= a1 && a1 <= b1 + 2 && b2 - 2 <= a2 && a2 <= b2 + 2){
		printf("0\n");
		return 0;
	}

	// 와드
	map[a1][a2] = 1;
	for(int i = 0; i < 24; i++){
		int na1 = a1 + dx[i];
		int na2 = a2 + dy[i];

		if(na1 >= 1 && na1 <= SIZE && na2 >= 1 && na2 <= SIZE && map[na1][na2] != 2){
			map[na1][na2] = 1;
		}
	}

	if(c1 <= a1 && a1 <= d1 && c2 <= a2 && a2 <= d2){
		for(int i = c1; i <= d1; i++){
			for(int j = c2; j <= d2; j++){
				if(map[i][j] == 0){
					map[i][j] = 1;
				}
			}
		}
	}

	int count = 0;
	for(int i = 1; i <= SIZE; i++){
		for(int j = 1; j <= SIZE; j++){
			if(map[i][j] == 1){
				count++;
			}
			// printf("%d ", map[i][j]);
		}
		// printf("\n");
	}

	printf("%d\n", count);


	return 0;
}
