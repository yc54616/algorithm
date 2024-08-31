#include <iostream>
#include <queue>

using namespace std;

static int T, N, M;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> T;
	for(int i = 0; i < T; i++){
		cin >> N >> M;
		
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		
		for(int j = 0; j < N; j++){
			int num;
			cin >> num;
			q.push({j, num});
			pq.push(num);
		}
		
		int count = 0;
		while(!pq.empty()){
			int index = q.front().first;
			int importance = q.front().second;
			q.pop();
			
			if(pq.top() == importance){
				pq.pop();
				count++;
				if(index == M){
					
					cout << count << "\n";
				}
			}
			else{
				q.push({index, importance});
			}	
		}
	}	
}
