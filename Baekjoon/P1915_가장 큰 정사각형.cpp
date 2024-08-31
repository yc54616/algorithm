#include <iostream>
#include <string>
#include <cmath>

using namespace std;

static int N, M;
static int D[1001][1001];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	long Max = 0;
	
	for(int i = 0; i < N; i++){
		string mline;
		cin >> mline;
		
		for(int j = 0; j < M; j++){
			D[i][j] = mline[j] - '0';
			
			if(D[i][j] == 1 && i > 0 && j > 0){
				D[i][j] = min(D[i - 1][j - 1], min(D[i - 1][j], D[i][j - 1])) + D[i][j];
			}
			if(D[i][j] > Max){
				Max = D[i][j];
			}
		}
		
	}
	cout << Max * Max;
	
}
