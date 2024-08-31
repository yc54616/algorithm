#include <iostream>
#include <string>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string A, B;
	int C;
	
	cin >> A >> B >> C;
	cout << stoi(A) + stoi(B) - C << "\n";
	cout << stoi(A+B) - C << "\n";
}
