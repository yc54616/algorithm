#include <iostream>

using namespace std;

static int N, K, A[101], D[10001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }
 
    for(int i = 1; i <= K; i++){
        D[i] = 100001;
    }

    for(int i = 1; i <= N; i++){
        for(int j = A[i]; j <= K; j++){
            D[j] = min(D[j], D[j - A[i]]+1);
        }
    }

    if(D[K] == 100001){
        cout << -1;
    }
    else{
        cout << D[K];
    }
    
}