#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, M;
	int start = 0;
	int end = 0;
	cin >> N >> M;
	vector<int> A(N);
	
	for(int i = 0; i < N; i++){
		cin >> A[i];
		if(A[i] > start)
			start = A[i];
		end += A[i];
	}
	
	while(start <= end){
		int mid = (start + end) / 2;
		int sum = 0;
		int count = 1;
		
		for(int i = 0; i < N; i++){
			if(sum + A[i] > mid){
				count++;
				sum = 0;
			}
			sum += A[i];
		}

		if(count <= M)
			end = mid - 1;		
		else
			start = mid + 1;
			
	}
	
	cout << start;
	
	
	
}
