#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

static int N;
static vector<pair<int, int>> A;

bool compare(pair<int, int> num1, pair<int, int> num2){
	if(num1.second == num2.second){
		return num1.first < num2.first;
	}
	return num1.second < num2.second;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for(int i = 0; i < N; i++){
		int num1, num2;
		cin >> num1 >> num2;
		A.push_back(make_pair(num1, num2));
	}
	
	sort(A.begin(), A.end(), compare);
	
	for(int i = 0; i < N; i++){
		cout << A[i].first << " " << A[i].second << "\n";
	}
	
	
}

