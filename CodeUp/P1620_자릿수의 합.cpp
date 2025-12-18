#include <iostream>
#include <string>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	
	string nStr = to_string(n);
	while(nStr.size() > 1){
		int tempSum = 0;
		for(int i = 0; i < nStr.size(); i++){
			tempSum += nStr[i] - '0';
		}
		nStr = to_string(tempSum);
	}
	
	cout << nStr;
	
}
