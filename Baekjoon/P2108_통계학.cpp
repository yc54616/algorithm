#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

static int N;
static vector<int> A;
static int seed[8001];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int Max = -4001;
	int Min = 4001;
	int sum = 0;
	
	cin >> N;
	A.resize(N);
	for(int i = 0; i < N; i++){
		cin >> A[i];
		sum += A[i];
		if(A[i] > Max){
			Max = A[i];
		}
		if(A[i] < Min){
			Min = A[i];
		}
		seed[A[i]+4000]++;
	}
	
	sort(A.begin(), A.end());
	
	int count = 0;
	int countNum = 4001;
	bool notfirst = false;
	
	for(int i = 0; i <= 8000; i++){
		if(seed[i]){
			if(seed[i] == count){
				if(notfirst){
					countNum = i-4000;
					notfirst = false;
				}
			}
			if(seed[i] > count){
				count = seed[i];
				countNum = i-4000;
				notfirst = true;
			}
		}
	}
	
	cout << (int)round((double)sum/N)  << "\n";
	cout << A[N/2] << "\n";
	cout << countNum << "\n";
	cout << Max - Min;
	
}
