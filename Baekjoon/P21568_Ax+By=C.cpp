#include <iostream>
#include <vector>

using namespace std;

vector<long long> Execute(long long a, long long b);
long long gcd(long long a, long long b);

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	long long a, b, c;
	cin >> a >> b >> c;
	long long tgcd = gcd(a, b);
	
	if(c % tgcd != 0)
		cout << -1;
	else{
		long long mok = c / tgcd;
		vector<long long> ret = Execute(a, b);
		cout << ret[0] * mok << " " << ret[1] * mok;
	}
}

vector<long long> Execute(long long a, long long b){
	vector<long long> ret(2);
	
	if(b == 0){
		ret[0] = 1;
		ret[1] = 0;
		return ret;
	}
	
	long long q = a / b;
	vector<long long> v = Execute(b, a % b);
	ret[0] = v[1];
	ret[1] = v[0] - v[1] * q;
	return ret;
}

long long gcd(long long a, long long b){
	if(b == 0)
		return a;
	else
		return gcd(b, a % b);
}

