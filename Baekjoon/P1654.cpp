#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

static long long N, K;
static vector<long long> A;

int checkN(int n);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    A.resize(N);
    long long Max = 0;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        Max = max(Max, A[i]);
    }

    long long start = 1;
    long long end = Max;
    long long ans = 0;
    while(start <= end){
        long long mid = (start + end)/2;
        long long target = checkN(mid);

        if(target >= K){
            ans = max(ans, mid);
            start = mid + 1;
        }
        else if(target < K)
            end = mid - 1;
    }

    cout << ans;
}

int checkN(int n){
    int cnt = 0;
    for(int i = 0; i < N; i++){
        cnt += A[i]/n;
    }

    return cnt;
}