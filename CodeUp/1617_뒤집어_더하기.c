#include <stdio.h>

static int reverse_int(int value) {
    int result = 0;
    while (value > 0) {
        result = result * 10 + (value % 10);
        value /= 10;
    }
    return result;
}

static int is_palindrome(int value) {
    return value == reverse_int(value);
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    int reversed = reverse_int(n);
    int sum = n + reversed;

    printf("%s\n", is_palindrome(sum) ? "YES" : "NO");
    return 0;
}
