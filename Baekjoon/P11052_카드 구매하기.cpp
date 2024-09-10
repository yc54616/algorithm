#include <iostream>

using namespace std;

static int N, D[10001], A[1001];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> A[i];
	}
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= i; j++){
			D[i] = max(D[i], D[i-j]+A[j]);
		}
	}
	
	cout << D[N];

}
