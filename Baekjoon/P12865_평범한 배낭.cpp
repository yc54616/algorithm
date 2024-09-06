#include <iostream>
#include <vector>

using namespace std;

static int N, K;
static int W[101];
static int V[101];
static int D[101][100001];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> K;
	for(int i = 1; i <= N; i++){
		cin >> W[i] >> V[i];
	}
	
	for(int k = 1; k <= N; k++){
		for(int w = 1; w <= K; w++){
			if(w >= W[k]){
				D[k][w] = max(D[k - 1][w], D[k - 1][w - W[k]]+V[k]);
			}
			else{
				D[k][w] = D[k - 1][w];
			}
		}
	}
	
	cout << D[N][K];
}
