#include <stdio.h>
#include <string.h>

#define MAX_SIZE 170

int main(void) {
    int a, b;
    if (scanf("%d %d", &a, &b) != 2) {
        return 0;
    }

    int X, Y, Z;
    scanf("%d %d %d", &X, &Y, &Z);

    int current[MAX_SIZE + 1][MAX_SIZE + 1];
    int next[MAX_SIZE + 1][MAX_SIZE + 1];
    memset(current, 0, sizeof(current));
    memset(next, 0, sizeof(next));

    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            scanf("%d", &current[i][j]);
        }
    }

    int k;
    scanf("%d", &k);

    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int step = 0; step < k; step++) {
        for (int i = 1; i <= a; i++) {
            for (int j = 1; j <= b; j++) {
                int sum = 0;
                for (int dir = 0; dir < 8; dir++) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if (nx < 1 || nx > a || ny < 1 || ny > b) {
                        continue;
                    }
                    sum += current[nx][ny];
                }

                if (current[i][j] == 0) {
                    next[i][j] = (sum == X) ? 1 : 0;
                } else {
                    if (sum < Y || sum >= Z) {
                        next[i][j] = 0;
                    } else {
                        next[i][j] = 1;
                    }
                }
            }
        }

        for (int i = 1; i <= a; i++) {
            for (int j = 1; j <= b; j++) {
                current[i][j] = next[i][j];
            }
        }
    }

    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            printf("%d ", current[i][j]);
        }
        printf("\n");
    }

    return 0;
}