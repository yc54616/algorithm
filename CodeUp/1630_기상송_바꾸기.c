#include <stdio.h>
#include <string.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }

    char line[128];
    for (int i = 0; i < n; i++) {
        if (!fgets(line, sizeof(line), stdin)) {
            return 0;
        }
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        printf("%s\n", line);
        if (i != n - 1) {
            printf("AMOLED\n");
        }
    }

    return 0;
}
