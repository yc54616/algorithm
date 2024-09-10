#include <iostream>

using namespace std;

static int N, A[1000], rD[1000], lD[1000];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	
	for(int i = 0; i < N; i++){
		rD[i] = 1;
		for(int j = 0; j < i; j++){
			if(A[i] > A[j]){
				rD[i] = max(rD[i], rD[j]+1);
			}
		}
	}
	
	for(int i = N - 1; i >= 0; i--){
		lD[i] = 1;
		for(int j = N - 1; j > i; j--){
			if(A[i] > A[j]){
				lD[i] = max(lD[i], lD[j]+1);
			}
		}
	}
	
	int ans = 0;
	for(int i = 0; i < N; i++){
		ans = max(ans, rD[i]+lD[i]);
	}
	cout << ans - 1;
	
	
}
