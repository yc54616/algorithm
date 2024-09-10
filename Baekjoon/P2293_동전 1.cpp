#include <iostream>

using namespace std;

static int N, K, D[10001], A[101];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> K;
	for(int i = 1; i <= N; i++){
		cin >> A[i];
	}
	
	D[0] = 1;
	for(int i = 1; i <= N; i++){
		for(int j = A[i]; j <= K; j++){
			D[j] = D[j] + D[j - A[i]];
		}
	}
	
	cout << D[K];
	
}
