#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(int node);
static vector<vector<int>> A;
static vector<int> answer;
static vector<bool> visited;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	A.resize(N + 1);
	answer.resize(N + 1);
	
	for(int i = 0; i < M; i++){
		int S, E;
		cin >> S >> E;
		A[S].push_back(E);
	}
	
	visited.resize(N + 1);
	for(int i = 1; i <= N; i++){
		fill(visited.begin(), visited.end(), false);
		BFS(i);
	}
	
	int maxVal = 0;
	for(int i = 1; i <= N; i++){
		maxVal = max(answer[i], maxVal);
	}
	for(int i = 1; i <= N; i++){
		if(answer[i] == maxVal){
			cout << i << " ";
		}
	}
	
	
}

void BFS(int node){
	queue<int> myQueue;
	myQueue.push(node);
	visited[node] = true;
	
	while(!myQueue.empty()){
		int nowNode = myQueue.front(); myQueue.pop();
		for(int nextNode : A[nowNode]){
			if(visited[nextNode] == false){
				visited[nextNode] = true;
				answer[nextNode]++;
				myQueue.push(nextNode);
			}
		}
	}
}


