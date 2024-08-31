#include <iostream>
#include <vector>

using namespace std;

void DFS(int node);
static vector<vector<int>> A;
static vector<int> check;
static vector<bool> visited;
static bool isEven;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	
	for(int i = 0; i < N; i++){
		int V, E;
		cin >> V >> E;
		A.resize(V + 1);
		check.resize(V + 1);
		visited.resize(V + 1);
		isEven = true;
		
		for(int i = 0; i < E; i++){
			int S, E;
			cin >> S >> E;
			A[S].push_back(E);
			A[E].push_back(S);
		}
		
		for(int i = 1; i <= V; i++){
			if(isEven){
				DFS(i);
			}
			else{
				break;
			}
		}
		
		if(isEven){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
		
		for(int i = 1; i <= V; i++){
			A[i].clear();
			check[i] = 0;
			visited[i] = false;
		}
	}
}

void DFS(int node){
	visited[node] = true;
	
	for(int nextNode : A[node]){
		if(!visited[nextNode]){
			check[nextNode] = (check[node] + 1) % 2;
			DFS(nextNode);
		}
		else if(check[nextNode] == check[node]){
			isEven = false;
		}
	}
}
