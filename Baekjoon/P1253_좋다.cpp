#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int N;
	cin >> N;
	vector<int> A(N, 0);
	
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	sort(A.begin(), A.begin()+N);
	
	int i;
	int j;
	int count = 0;
	int find;
	
	for(int k = 0; k < N; k++){
		i = 0;
		j = N - 1;
		find = A[k];
		while(i < j){
			if(A[i] + A[j] == find){
				if(i != k && j != k){ // A[i], A[j]가 0이 나올 수 도 있음 
					count++;
					break;
				}
				else if(i == k){
					i++;
				}
				else if(j == k){
					j--;
				}
			}
			else if(A[i] + A[j] < find){
				i++;
			}
			else{
				j--;
			}
		}
	}
	cout << count << "\n";
	
	
}
