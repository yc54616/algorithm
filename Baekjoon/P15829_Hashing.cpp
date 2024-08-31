#include <iostream>

using namespace std;

static int L;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> L;
	char temp;
	long long int num;
	long long int sum = 0;
	long long int M = 1234567891;
	long long int r = 1;
	for(int i = 0; i < L; i++){
		cin >> temp;
		num = (temp - 'a' + 1);
		sum += (num * r) % M;
		r = r * 31 % M;
	}
	
	cout << sum%M;
}
