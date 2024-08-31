#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	long long Min, Max;
	cin >> Min >> Max;
	vector<bool> Check(Max - Min + 1);
	
	for(long long i = 2; i * i <= Max; i++){
		long long pow = i * i;
		long long startIndex = Min / pow;
		
		if(Min % pow)
			startIndex++;
		for(long long j = startIndex; pow * j <= Max; j++)
			Check[j * pow - Min] = true;
	}
	
	int count = 0;
	
	for(int i = 0; i <= Max - Min; i++){
		if(!Check[i])
			count++;
	}
	
	cout << count;
}
