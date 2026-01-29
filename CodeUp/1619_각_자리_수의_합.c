#include <stdio.h>

static int digit_sum(int value) {
    int sum = 0;
    while (value > 0) {
        sum += value % 10;
        value /= 10;
    }
    return sum;
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    int sum = digit_sum(n);
    if (n % sum == 0) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
