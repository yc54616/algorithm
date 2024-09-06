#include <iostream>

using namespace std;

static int N;
static int A[3][1001], D[3][1001];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> A[0][i] >> A[1][i] >> A[2][i];
	}
	
	for(int i = 1; i <= N; i++){
		D[0][i] = min(D[1][i-1], D[2][i-1]) + A[0][i];
		D[1][i] = min(D[0][i-1], D[2][i-1]) + A[1][i];
		D[2][i] = min(D[0][i-1], D[1][i-1]) + A[2][i];
	}
	
	cout << min(D[0][N], min(D[1][N], D[2][N]));
	
}
