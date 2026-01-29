#include <stdio.h>
#include <string.h>

#define SIZE 10
#define MAX_PLAYERS 8

int main(void) {
    int map[SIZE + 1][SIZE + 1];
    int water[SIZE + 1][SIZE + 1];
    memset(map, 0, sizeof(map));
    memset(water, 0, sizeof(water));

    for (int i = 1; i <= SIZE; i++) {
        for (int j = 1; j <= SIZE; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    int n;
    scanf("%d", &n);
    int players[MAX_PLAYERS + 1][2];
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &players[i][0], &players[i][1]);
    }

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    for (int i = 1; i <= SIZE; i++) {
        for (int j = 1; j <= SIZE; j++) {
            if (map[i][j] > 0) {
                int power = map[i][j];
                water[i][j] = 1;
                for (int dir = 0; dir < 4; dir++) {
                    for (int step = 1; step <= power; step++) {
                        int nx = i + dx[dir] * step;
                        int ny = j + dy[dir] * step;
                        if (nx < 1 || nx > SIZE || ny < 1 || ny > SIZE) {
                            break;
                        }
                        if (map[nx][ny] == -1) {
                            break;
                        }
                        water[nx][ny] = 1;
                    }
                }
            }
        }
    }

    int alive[MAX_PLAYERS + 1];
    for (int i = 1; i <= n; i++) {
        int px = players[i][0];
        int py = players[i][1];
        alive[i] = water[px][py] ? 0 : 1;
    }

    int board[SIZE + 1][SIZE + 1];
    for (int i = 1; i <= SIZE; i++) {
        for (int j = 1; j <= SIZE; j++) {
            if (map[i][j] == -1) {
                board[i][j] = -1;
            } else if (water[i][j]) {
                board[i][j] = -2;
            } else {
                board[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (alive[i]) {
            int px = players[i][0];
            int py = players[i][1];
            board[px][py] = i;
        }
    }

    for (int i = 1; i <= SIZE; i++) {
        for (int j = 1; j <= SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    printf("Character Information\n");
    for (int i = 1; i <= n; i++) {
        printf("player %d %s\n", i, alive[i] ? "survive" : "dead");
    }

    return 0;
}
