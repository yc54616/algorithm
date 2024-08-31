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
	vector<int> ans(N, 0);
	
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	
	stack<int> mystack;
	mystack.push(0);
	
	for(int i = 1; i < N; i++){
		while(mystack.size() && A[i] > A[mystack.top()]){
			ans[mystack.top()] = A[i];
			mystack.pop();
		}
		mystack.push(i);
	}
	while(mystack.size()){
		ans[mystack.top()] = -1;
		mystack.pop();
	}
	
	for(int i = 0; i < N; i++){
		cout << ans[i] << " ";
	}
	
}

