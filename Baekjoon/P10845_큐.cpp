#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	string str;
	queue<int> myQueue;
	for(int i = 0; i < N; i++){
		cin >> str;
		if(str == "push"){
			int n;
			cin >> n;
			myQueue.push(n);
		}
		else if(str == "pop"){
			if(myQueue.empty())
				cout << "-1\n";
			else{
				int temp = myQueue.front();
				myQueue.pop();
				cout << temp << "\n";
			}
		}
		else if(str == "size")
			cout << myQueue.size() << "\n";
		else if(str == "empty")
			cout << myQueue.empty() << "\n";
		else if(str == "front"){
			if(myQueue.empty())
				cout << "-1\n";
			else
				cout << myQueue.front() << "\n";
		}
		else if(str == "back"){
			if(myQueue.empty())
				cout << "-1\n";
			else
				cout << myQueue.back() << "\n";
		}
	}
}
