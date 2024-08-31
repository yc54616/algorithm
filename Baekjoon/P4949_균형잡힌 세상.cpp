#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	while(true){
		string temp = "";
		stack<char> s;
		bool check = true;
		
		getline(cin, temp);
		if(temp.length() == 1 && temp[0] == '.'){
			break;
		}
		
		for(int i = 0; i < temp.length(); i++){
			if(temp[i] == '[' || temp[i] == '('){
				s.push(temp[i]);
			}
			if(temp[i] == ']'){
				if(!s.empty() && s.top() == '[' ){
					s.pop();
				}
				else{
					check = false;
					break;
				}
			}
			else if(temp[i] == ')'){
				if(!s.empty() && s.top() == '(' ){
					s.pop();
				}
				else{
					check = false;
					break;
				}
			}
		}
		
		if(check && s.empty()){
			cout << "yes\n";
		}
		else{
			cout << "no\n";
		}
	}
}
