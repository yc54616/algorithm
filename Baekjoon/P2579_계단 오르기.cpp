#include <iostream>
#include <cmath>

using namespace std;

static int N;
static int A[300], D[300];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	
	D[0] = A[0];
	D[1] = max(A[0]+A[1], A[1]);
	D[2] = max(A[1]+A[2], A[0]+A[2]);
	
	for(int i = 3; i < N; i++){
		D[i] = A[i] + max(A[i - 1] + D[i - 3], D[i-2]);
	}
	
	cout << D[N - 1];
	
}
