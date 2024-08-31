#include <iostream>
#include <queue>

using namespace std;

void BFS();
static int sender[] = {0, 0, 1, 1, 2, 2};
static int receiver[] = {1, 2, 0, 2, 0, 1};
static bool visited[201][201];
static bool answer[201];
static int now[3];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> now[0] >> now[1] >> now[2];
	BFS();
	
	for(int i = 0; i <= now[2]; i++){
		if(answer[i]){
			cout << i << " ";
		}
	}
}

void BFS(){
	queue<pair<int, int>> myQueue;
	myQueue.push(make_pair(0, 0));
	visited[0][0] = true;
	answer[now[2]] = true;
	
	while(!myQueue.empty()){
		pair<int, int> p = myQueue.front(); myQueue.pop();
		int A = p.first;
		int B = p.second;
		int C = now[2] - A - B;
		
		for(int k = 0; k < 6; k++){
			int next[] = {A, B, C};
			next[receiver[k]] += next[sender[k]];
			next[sender[k]] = 0;
			
			if(next[receiver[k]] > now[receiver[k]]){
				next[sender[k]] = next[receiver[k]] - now[receiver[k]];
				next[receiver[k]] = now[receiver[k]];
			}
			
			if(!visited[next[0]][next[1]]){
				visited[next[0]][next[1]] = true;
				myQueue.push(make_pair(next[0], next[1]));
				
				if(next[0] == 0){
					answer[next[2]] = true;
				}
			}
			
		}
	}
}
