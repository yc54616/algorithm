#include <iostream>
#include <queue>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	priority_queue<int> plusPq;
	priority_queue<int, vector<int>, greater<int>> minusPq;
	int one = 0;
	int zero = 0;
	
	int data;
	for(int i = 0; i < N; i++){
		cin >> data;
		if(data > 1)
			plusPq.push(data);
		else if(data == 1)
			one++;
		else if(data == 0)
			zero++;
		else
			minusPq.push(data);
	}
	
	int sum = 0;
	int first, second;
	
	while(plusPq.size() > 1){
		first = plusPq.top();
		plusPq.pop();
		second = plusPq.top();
		plusPq.pop();
		sum += (first * second);
	}
	if(!plusPq.empty()){
		sum += plusPq.top();
		plusPq.pop();
	}
	
	while(minusPq.size() > 1){
		first = minusPq.top();
		minusPq.pop();
		second = minusPq.top();
		minusPq.pop();
		sum += (first * second);
	}
	if(!minusPq.empty()){
		if(zero == 0){
			sum += minusPq.top();
			minusPq.pop();
		}
	}
	
	sum += one;
	cout << sum;
		
}
