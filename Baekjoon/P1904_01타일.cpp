#include <iostream>

using namespace std;

static int N, D[1000001];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	D[0] = 1;
	for(int i = 1; i <= N; i++){
		D[i] = D[i - 1]%15746 + D[i - 2]%15746;
		D[i] = D[i]%15746;
	}
	
	cout << D[N];
}
