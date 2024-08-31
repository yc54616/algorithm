#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool campare(pair<int, string> a, pair<int, string> b){
	return a.first < b.first;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	vector<pair<int, string>> A(N);
	for(int i = 0; i < N; i++)
		cin >> A[i].first >> A[i].second;
	
	stable_sort(A.begin(), A.end(), campare);
	
	for(int i = 0; i < N; i++)
		cout << A[i].first << " " << A[i].second << "\n";
}
