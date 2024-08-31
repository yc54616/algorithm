#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int a, b;
	cin >> a >> b;
	vector<int> A(5001);
	vector<int> check(5001, true);
	
	for(int i = 1; i <= 5000; i++){
		A[i] = i;
	}
	
	for(int i = 1; i <= 5000; i++){
		string temp = to_string(A[i]);
		int sum = 0;
		for(int j = 0; j < temp.length(); j++){
			sum += temp[j] - '0';
		}  
		sum += stoi(temp);
		if(sum <= b && check[sum])
			check[sum] = false;
	}
	
	int sum = 0;
	for(int i = a; i <= b; i++){
		if(check[i]){
			sum += A[i];
		}
			
	}
	cout << sum;
}
