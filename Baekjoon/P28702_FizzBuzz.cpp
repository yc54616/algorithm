#include <iostream>
#include <string>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string temp;
	bool myNumCheck = false;
	int myNum = 0;
	int changeNum = 0;
	for(int i = 0; i < 3; i++){
		cin >> temp;
		changeNum = atoi(temp.c_str());
		if(changeNum != 0){
			myNumCheck = true;
			myNum = changeNum;
		}
		if(myNumCheck){
			myNum++;
		}
	}
	
	if(myNum % 3 == 0 && myNum % 5 == 0){
		cout << "FizzBuzz";
	}
	else if(myNum % 3 == 0){
		cout << "Fizz";
	}
	else if(myNum % 5 == 0){
		cout << "Buzz";
	}
	else{
		cout << myNum;
	}
}
