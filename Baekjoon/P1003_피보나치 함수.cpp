#include <iostream>

using namespace std;

static int T;
static int zero[41] = {1, 0};
static int one[41] = {0, 1};

int main(){	
	for(int i = 2; i <= 40; i++){
		zero[i] = zero[i-1] + zero[i-2];
		one[i] = one[i-1] + one[i-2];
	}

	cin >> T;
	
	for(int i = 0; i < T; i++){
		int N;
		cin >> N;
		cout << zero[N] << " " << one[N] << "\n";
	}

}
