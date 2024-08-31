#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	vector<int> A(N, 0);
	vector<char> result;
	
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	
	stack<int> mystack;
	bool check = true;
	int num = 1;
	
	for(int i = 0; i < A.size(); i++){
		int su = A[i];
		if(su >= num){
			while(su >= num){
				mystack.push(num++);
				result.push_back('+');
			}
			mystack.pop();
			result.push_back('-');
		}	
		else{
			int n = mystack.top();
			mystack.pop();
			if(n > su){
				cout << "NO\n"; 
				check = false;
				break;
			} 
			else{
				result.push_back('-');
			}
			
		}
	} 
	
	if(check){
		for(int i = 0; i < result.size(); i++){
			cout << result[i] << "\n";
		}
	}
	
}
