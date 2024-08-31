#include <iostream>

using namespace std;

static int N;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	
	long long int number = 667;
	int check = 1;
	while(true){
		if(check == N){
			cout << number - 1;
			break;
		}
		long long int copyNumber = number;
		while(copyNumber > 0){
			if(copyNumber % 1000 == 666){
				check++;
				break;
			}
			copyNumber /= 10;
		}
		number++;
	}
}
