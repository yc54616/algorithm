#include <iostream>
#include <deque>

using namespace std;
typedef pair<int, int> Node;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, L;
	deque<Node> D;
	
	cin >> N >> L;
	for(int i = 1; i <= N; i++){
		int now;
		cin >> now;
		
		while(D.size() && D.back().second > now)
			D.pop_back();
		D.push_back(Node(i, now));
		
		if(D.back().first - D.front().first >= L)
			D.pop_front();
			
		cout << D.front().second << " ";
	}
	
}
