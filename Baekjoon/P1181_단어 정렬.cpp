#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool wordCompare(string word1, string word2);

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	
	vector<string> A(N);
	string tmp = "";
	
	for(int i = 0; i < N; i++)
		cin >> A[i];
	
	sort(A.begin(), A.end(), wordCompare);
	
	for(int i = 0; i < N; i++){
		if(tmp == A[i])
			continue;
		cout << A[i] << "\n";
		tmp = A[i];
	}
	
}

bool wordCompare(string word1, string word2){ 
	if(word1.length() == word2.length()){
		return word1 < word2;
	}
	return word1.length() < word2.length();
}
