#include <iostream>

using namespace std;

static int N, D[45];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	D[0] = 0;
	D[1] = 1;
	
	for(int i = 2; i <= N; i++){
		D[i] = D[i - 1] + D[i - 2];
	}
	
	cout << D[N];
}
