#include <iostream>
#include <vector>

using namespace std;

static int N;
static int result[50];
static vector<pair<int, int>> A;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for(int i = 0; i < N; i++){
		int x, y;
		cin >> x >> y;
		A.push_back(make_pair(x, y));
	}
	
	int count;
	for(int i = 0; i < N; i++){
		count = 0;
		for(int j = 0; j < N; j++){
			if(i == j){
				continue;
			}
			if(A[i].first < A[j].first && A[i].second < A[j].second){
				count++;
			}
		}
		result[i] = count+1;
	}
	
	for(int i = 0; i < N; i++){
		cout << result[i] << " ";
	}
	
}

