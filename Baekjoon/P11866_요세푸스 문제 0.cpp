#include <iostream>
#include <queue>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, K;
	cin >> N >> K;
	queue<int> myQueue;
	
	for(int i = 1; i <= N; i++){
		myQueue.push(i);
	}
	
	int count = 1;
	int data;
	cout << "<";
	while(!myQueue.empty()){
		data = myQueue.front();
		myQueue.pop();
		if(count++%K == 0){
			cout << data;
			if(myQueue.size() >= 1)
				cout << ", ";
		}
		else
			myQueue.push(data);
	}
	cout << ">";
}
