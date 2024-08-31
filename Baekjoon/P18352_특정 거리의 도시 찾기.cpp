#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void BFS(int node);
static vector<vector<int>> A;
static vector<int> answer;
static vector<int> visited;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, M, K, X;
	cin >> N >> M >> K >> X;
	A.resize(N + 1);
	
	for(int i = 0; i < M; i++){
		int S, E;
		cin >> S >> E;
		A[S].push_back(E);
	}
	
	visited.resize(N + 1);
	for(int i = 1; i <= N; i++){
		visited[i] = -1;
	}
	
	BFS(X);
	
	for(int i = 1; i <= N; i++){
		if(visited[i] == K){
			answer.push_back(i);
		}
	}
	if(answer.empty()){
		cout << -1;
	}
	else{
		sort(answer.begin(), answer.end());
		for(int temp : answer){
			cout << temp << "\n";
		}
	}

}

void BFS(int node){
	queue<int> myQueue;
	myQueue.push(node);
	visited[node]++;
	
	while(!myQueue.empty()){
		int nowNode = myQueue.front(); myQueue.pop();
		for(int nextNode : A[nowNode]){
			if(visited[nextNode] == -1){
				visited[nextNode] = visited[nowNode] + 1;
				myQueue.push(nextNode);
			}
		}
	}
}
