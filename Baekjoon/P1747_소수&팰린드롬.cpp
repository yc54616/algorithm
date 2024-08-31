#include <iostream>
#include <cmath>
#include <string>
#define MAX 10000001

long long A[MAX];

using namespace std;

bool isPalindrome(long long target);

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	long long N;
	cin >> N;
	for(int i = 2; i < MAX; i++)
		A[i] = i;
		
	for(int i = 2; i < sqrt(MAX); i++){
		if(A[i] == 0)
			continue;
		for(int j = i + i; j < MAX; j+=i)
			A[j] = 0;
	}
	
	int i = N;
	
	while(true){
		if(A[i]){
			long long result = A[i];
			if(isPalindrome(result)){
				cout << result;
				break;
			}
		}
		i++;
	}
}

bool isPalindrome(long long target){
	string tempStr = to_string(target);
	int e = tempStr.size() - 1;
	for(int s = 0; s <= e; s++){
		if(tempStr[s] != tempStr[e - s])
			return false;
	}
	return true;
}
