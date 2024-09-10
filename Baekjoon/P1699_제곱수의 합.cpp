//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//static int N, D[100001];
//
//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	
//	cin >> N;
//	
//	for(int i = 1; i <= N; i++){ // 5
//		for(int j = 1; j <= sqrt(i); j++){ // 4
//			if(i == pow(j, 2)){
//				D[i] = 1;
//			}
//			else{
//				D[i] = D[i-(int)pow(j, 2)]+1;
//			}	
//		}
//	}
//	
//	for(int i = 1; i <= N; i++){
//		cout << D[i] << " ";
//	}
//}
#include <iostream>

using namespace std;

static int N, D[100001];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++){
		D[i] = i;
	}
	
	for(int i = 1; i <= N; i++){ // 5
		for(int j = 1; j * j <= i; j++){ // 4
			D[i] = min(D[i], D[i-j*j]+1);
		}
	}
	
	cout << D[N];
}
