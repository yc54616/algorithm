#include <iostream>

using namespace std;

static int N, D[1001], A[1001];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	
	int ans = 0;
	for(int i = N - 1; i >= 0; i--){
		D[i] = 1;
		for(int j = N - 1; j > i; j--){
			if(A[i] > A[j]){
				D[i] = max(D[i], D[j]+1);
			}
		}
		ans = max(ans, D[i]);
	}
	
	cout << ans;
}
