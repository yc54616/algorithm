#include <stdio.h>

#define SIZE 7

int main(void) {
    int laser[SIZE + 1][SIZE + 1] = {0};
    int splitter[SIZE + 1][SIZE + 1] = {0};
    int visited[SIZE + 1][SIZE + 1][4] = {0};
    int splitters[3][2];

    for (int i = 0; i < 3; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        splitters[i][0] = x;
        splitters[i][1] = y;
        splitter[x][y] = 1;
    }

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int qx[4096];
    int qy[4096];
    int qd[4096];
    int head = 0;
    int tail = 0;

    qx[tail] = 4;
    qy[tail] = 0;
    qd[tail] = 3;
    tail++;

    while (head < tail) {
        int x = qx[head];
        int y = qy[head];
        int dir = qd[head];
        head++;

        while (1) {
            x += dx[dir];
            y += dy[dir];

            if (x < 1 || x > SIZE || y < 1 || y > SIZE) {
                break;
            }

            if (visited[x][y][dir]) {
                break;
            }
            visited[x][y][dir] = 1;

            if (!splitter[x][y]) {
                laser[x][y] = 1;
            }

            if (splitter[x][y]) {
                if (dir == 0 || dir == 1) {
                    qx[tail] = x;
                    qy[tail] = y;
                    qd[tail] = 2;
                    tail++;

                    qx[tail] = x;
                    qy[tail] = y;
                    qd[tail] = 3;
                    tail++;
                } else {
                    qx[tail] = x;
                    qy[tail] = y;
                    qd[tail] = 0;
                    tail++;

                    qx[tail] = x;
                    qy[tail] = y;
                    qd[tail] = 1;
                    tail++;
                }
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        int x = splitters[i][0];
        int y = splitters[i][1];
        laser[x][y] = 2;
    }

    for (int i = 1; i <= SIZE; i++) {
        for (int j = 1; j <= SIZE; j++) {
            printf("%d ", laser[i][j]);
        }
        printf("\n");
    }

    return 0;
}
