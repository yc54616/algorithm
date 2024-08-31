#include <iostream>
#include <cmath>

using namespace std;

static int N, T[16], P[16], D[16];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> T[i] >> P[i];
	}
	
	for(int i = N; i >= 1; i--){
		if(T[i] + i > N + 1){
			D[i] = D[i + 1];
		}
		else{
			D[i] = max(D[i + 1], D[T[i] + i] + P[i]);
		}
	}
	
	cout << D[1];
			
}
