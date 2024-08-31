//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//static int N;
//static int A[100001];
//static int D[2][100001];
//static int result;
//
//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	
//	cin >> N;
//	
//	for(int i = 0; i < N; i++){
//		cin >> A[i];
//	}
//	
//	D[0][0] = A[0];
//	D[1][0] = A[0];
//	result = A[0];
//	
//	for(int i = 1; i < N; i++){
//		D[0][i] = max(D[0][i-1]+A[i], A[i]);
//		D[1][i] = max(D[0][i-1], D[1][i-1]+A[i]);
//		result = max(result, max(D[0][i], D[1][i]));
//	}
//	
//	cout << result;
//	
//}
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

static int N;
static vector<int> A, L, R;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	A.resize(N);
	
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	
	L.resize(N);
	L[0] = A[0];
	int result = L[0];
	
	for(int i = 1; i < N; i++){
		L[i] = max(L[i - 1] + A[i], A[i]);
		result = max(result, L[i]);
	}
	
	R.resize(N);
	R[N - 1] = A[N - 1];
	
	for(int i = N - 2; i >= 0; i--){
		R[i] = max(A[i], R[i + 1] + A[i]);
	}
	
	for(int i = 1; i < N - 1; i++){
		int temp = L[i - 1] + R[i + 1];
		result = max(result, temp);
	}
	
	cout << result;
}
