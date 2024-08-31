#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string str;
	cin >> str;
	
	vector<int> A(str.size());
	
	for(int i = 0; i < str.size(); i++){
		A[i] = stoi(str.substr(i, 1));
	}
	
	for(int i = 0; i < str.size(); i++){
		int Max = i;
		for(int j = i+1; j < str.size(); j++){
			if(A[j] > A[Max]){
				Max = j;
			}
		}
		if(A[Max] > A[i]){
			int temp = A[Max];
			A[Max] = A[i];
			A[i] = temp;
		}
	}
	
	for(int i = 0; i < str.size(); i++){
		cout << A[i];
	}
}
