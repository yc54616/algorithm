#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

static int N, M;
static vector<int> T;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    T.resize(N);

    ull sum = 0;
    for(int i = 0; i < N; i++){
        cin >> T[i];
        sum += T[i];
    }

    ull start = 1;
    ull end = sum*M;
    ull ans = 1e19;

    while (start <= end){
        ull mid = (start+end)/2;
        ull target = 0;

        for(int i = 0; i < N; i++){
            target += mid/T[i];
        }

        if(target >= M){
            ans = min(ans, mid);
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }

    }

    cout << ans;
    



}