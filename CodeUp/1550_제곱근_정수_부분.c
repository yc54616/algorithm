long long int sqrt(long long int n) {
    if (n == 0) {
        return 0;
    }

    long long int left = 1;
    long long int right = n;
    long long int answer = 0;

    while (left <= right) {
        long long int mid = (left + right) / 2;
        if (mid <= n / mid) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return answer;
}
