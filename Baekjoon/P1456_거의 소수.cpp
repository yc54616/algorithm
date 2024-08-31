#include <iostream>
#include <cmath>
#define N 10000001

using namespace std;

long long A[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	long long Min, Max;
	cin >> Min >> Max;
	
	for(int i = 2; i < N; i++)
		A[i] = i;
	
	for(int i = 2; i < sqrt(N); i++){
		if(A[i] == 0)
			continue;
		for(int j = i + i; j < N; j+=i)
			A[j] = 0;
	}
	
	int count = 0;
	for(int i = 2; i < N; i++){
		if(A[i]){
			long long temp = A[i];
			while((long double)A[i] <= (long double)Max/(long double)temp){
				if((long double)A[i] >= (long double)Min/(long double)temp)
					count++;
				temp *= A[i];
			}	
		}
	}
	
	cout << count;
}
