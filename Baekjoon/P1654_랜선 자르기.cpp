#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

static unsigned K, N;
static vector<unsigned> A;

bool checkN(unsigned mid);

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> K >> N;
	A.resize(K);
	
	unsigned start = 1;
	unsigned end = 0;
	for(int i = 0; i < K; i++){
		cin >> A[i];
		end = max(end, A[i]);
	}
	
	unsigned result = 0;
	while(start <= end){
		unsigned mid = (start + end) / 2;
		
		if(checkN(mid)){
			result = max(result, mid);
			start = mid + 1;
		}
		else{
			end = mid - 1;
		}
	}
	
	cout << result;
}

bool checkN(unsigned mid){
	unsigned cnt = 0;
	
	for(int i = 0; i < K; i++){
		cnt += (A[i]/mid);
	}
	
	if(cnt >= N){
		return true;
	}
	else{
		return false;
	}
	
}
