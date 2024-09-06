#include <iostream>

using namespace std;

static int N, D[502][502];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= i; j++){
			cin >> D[i][j];
		}
	}
	
	for(int i = N - 1; i >= 1; i--){
		for(int j = 1; j <= i; j++){
			D[i][j] += max(D[i+1][j], D[i+1][j+1]);
		}
	}
	
	cout << D[1][1];
}
