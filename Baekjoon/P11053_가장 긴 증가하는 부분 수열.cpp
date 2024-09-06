#include <iostream>

using namespace std;

static int N, A[1000], D[1000];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	
	int ans = 0;
	for(int i = 0; i < N; i++){
		D[i] = 1;
		for(int j = 0; j < i; j++){
			if(A[i] > A[j]){
				D[i] = max(D[i], D[j]+1);
			}
		}
		ans = max(D[i], ans);
	}
	
	cout << ans;
	
	
}
