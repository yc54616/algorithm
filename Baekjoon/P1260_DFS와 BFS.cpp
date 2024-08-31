#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

static vector<vector <int>> A;
static vector<bool> visited;

void DFS(int node);
void BFS(int node);

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, M, start;
	cin >> N >> M >> start;
	A.resize(N + 1);
	
	for(int i = 0; i < M; i++){
		int s, e;
		cin >> s >> e;
		A[s].push_back(e);
		A[e].push_back(s);
	}
	
	for(int i = 1; i <= N; i++){
		sort(A[i].begin(), A[i].end());
	}
	
	visited = vector<bool>(N + 1, false);
	DFS(start);
	cout << "\n";
	fill(visited.begin(), visited.end(), false);
	BFS(start);

	return 0;
}

void DFS(int node){
	if(visited[node])
		return;
	
	cout << node << " ";
	visited[node] = true;
	
	for(int i : A[node]){
		if(!visited[i])
			DFS(i);
	}
}

void BFS(int node){
	queue<int> myqueue;
	myqueue.push(node);
	visited[node] = true;
	
	while(!myqueue.empty()){
		int nowNode = myqueue.front();
		myqueue.pop();
		cout << nowNode << " ";
		for(int i : A[nowNode]){
			if(!visited[i]){
				visited[i] = true;
				myqueue.push(i);
			}
		}
	}
}
