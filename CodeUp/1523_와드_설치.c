#include <stdio.h>

#define SIZE 9

int in_range(int x, int y) {
    return x >= 1 && x <= SIZE && y >= 1 && y <= SIZE;
}

int main(void) {
    int a1, a2;
    int b1, b2;
    int c1, c2, d1, d2;

    if (scanf("%d %d", &a1, &a2) != 2) {
        return 0;
    }
    scanf("%d %d", &b1, &b2);
    scanf("%d %d", &c1, &c2);
    scanf("%d %d", &d1, &d2);

    int lit[SIZE + 1][SIZE + 1] = {0};
    int lens[SIZE + 1][SIZE + 1] = {0};

    for (int x = b1 - 2; x <= b1 + 2; x++) {
        for (int y = b2 - 2; y <= b2 + 2; y++) {
            if (in_range(x, y)) {
                lens[x][y] = 1;
            }
        }
    }

    if (lens[a1][a2]) {
        printf("0\n");
        return 0;
    }

    for (int x = a1 - 2; x <= a1 + 2; x++) {
        for (int y = a2 - 2; y <= a2 + 2; y++) {
            if (in_range(x, y)) {
                lit[x][y] = 1;
            }
        }
    }

    if (c1 <= a1 && a1 <= d1 && c2 <= a2 && a2 <= d2) {
        for (int x = c1; x <= d1; x++) {
            for (int y = c2; y <= d2; y++) {
                lit[x][y] = 1;
            }
        }
    }

    for (int x = 1; x <= SIZE; x++) {
        for (int y = 1; y <= SIZE; y++) {
            if (lens[x][y]) {
                lit[x][y] = 0;
            }
        }
    }

    int count = 0;
    for (int i = 1; i <= SIZE; i++) {
        for (int j = 1; j <= SIZE; j++) {
            if (lit[i][j]) {
                count++;
            }
        }
    }

    printf("%d\n", count);
    return 0;
}
