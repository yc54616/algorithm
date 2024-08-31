#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

static int N;
static vector<int> A;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	A.resize(N);
	int sum = 0;
	for(int i = 0; i < N; i++){
		cin >> A[i];
		sum += A[i];
	}
	sort(A.begin(), A.end());
	
	int count = round(N*0.15);
	for(int i = 0; i < count; i++){
		sum -= A[i];
		sum -= A[N - 1 - i];
	}
	
	if(N==0){
		cout << 0;
	}
	else{
		cout << round(sum/(N-2.0*count));
	}
}
