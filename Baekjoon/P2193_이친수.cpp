#include <iostream>

using namespace std;

static long long N, D[91];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	
	D[1] = 1;
	D[2] = 1;
	for(int i = 3; i <= N; i++){
		D[i] = D[i - 1] + D[i - 2];
	}
	
	cout << D[N];
	
	return 0;
}
