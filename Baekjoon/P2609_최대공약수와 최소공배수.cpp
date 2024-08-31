#include <iostream>

using namespace std;

static int A, B;
int gcd(int a, int b);

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> A >> B;

	int GCD = gcd(A, B);
	cout << GCD << "\n" << A*B/GCD;
}

int gcd(int a, int b){
	if(b == 0){
		return a;
	}
	else{
		return gcd(b, a%b);
	}
}
