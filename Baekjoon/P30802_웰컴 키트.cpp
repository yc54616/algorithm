#include <iostream>

using namespace std;

static int N, T, P;
static int A[6];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for(int i = 0; i < 6; i++){
		cin >> A[i];
	}
	cin >> T >> P;
	
	int sum = 0;
	for(int i = 0; i < 6; i++){
		sum += (A[i]+T-1)/T;
	}
	cout << sum << "\n";
	cout << N/P << " " << N%P;
}
