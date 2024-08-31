#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, K;
	cin >> N >> K;
	vector<int> A(N);
	
	for(int i = 0; i < N; i++)
		cin >> A[i];
	
	int i, j, key;
	int ans = -1;
	int count = 0;
	for(i = 1; i < N; i++){
		key = A[i];
		for(j = i - 1; j >= 0 && A[j] > key; j--){
			if(++count == K)
				ans = A[j];
			A[j+1] = A[j];
		}
		if(A[i] != key){
			if(++count == K)
				ans = key;
			A[j+1] = key;
		}
	}
	
	cout << ans;

	return 0;
	
}
