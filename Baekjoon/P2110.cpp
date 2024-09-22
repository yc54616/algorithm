#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

static ll N, C;
static vector<ll> A;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> C;
    A.resize(N);

    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    ll start = 1;
    ll end = A[N - 1] - A[0];
    ll ans = 0;

    while(start <= end){
        ll mid = (start+end)/2;
        ll router = 1;
        ll prePos = A[0];

        for(int i = 0; i < N; i++){
            if(A[i] - prePos >= mid){
                router++;
                prePos = A[i];
            }
        }

        if(router >= C){
            ans = max(ans, mid);
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }

    cout << ans;

}