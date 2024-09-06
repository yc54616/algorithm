#include <iostream>
#include <string>

using namespace std;

static int N, D[1001][1001];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string str1, str2;
	cin >> str1 >> str2;
	
	for(int i = 1; i <= str1.size(); i++){
		for(int j = 1; j <= str2.size(); j++){
			if(str1[i-1] == str2[j-1]){
				D[i][j] = D[i-1][j-1] + 1;
			}
			else{
				D[i][j] = max(D[i][j - 1], D[i - 1][j]);
			}
		}
	}
	
	cout << D[str1.size()][str2.size()];
	
}
