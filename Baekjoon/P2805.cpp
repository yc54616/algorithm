#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

static ll N, M;
static vector<ll> A;

bool checkN(ll target);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    A.resize(N);
    
    ll Max = 0;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        Max = max(Max, A[i]);
    }

    ll start = 1;
    ll end = Max;
    ll ans = 0;

    while(start <= end){
        ll mid = (start+end)/2;

        if(checkN(mid)){
            ans = max(ans, mid);
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }

    cout << ans;
}

bool checkN(ll target){
    ll sum = 0;
    for(int i = 0; i < N; i++){
        if(A[i] > target){
            sum += A[i]-target;
        }
    }
    if(sum >= M)
        return true;
    else
        return false;
}