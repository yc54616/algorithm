#include <iostream>
#include <map>

using namespace std;

static int N, M;
static long temp;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	map<int, int> myMap;
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> temp;
		myMap[temp]++;
	}
	cin >> M;
	for(int i = 0; i < M; i++){
		cin >> temp;
		cout << myMap[temp] << " ";
	}
}
