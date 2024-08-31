/*
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int num[1000] = {
    0,
};

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }
    sort(num, num + N);
    for (int i = 0; i < N; i++)
    {
        cout << num[i] << endl;
    }
}
*/
#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	vector<int> A(N, 0);
	
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	
	for(int i = 0; i < N - 1; i++){
		for(int j = 0; j < N - 1 - i; j++){
			if(A[j] > A[j+1]){
				A[j] = A[j] ^ A[j+1];
				A[j+1] = A[j] ^ A[j+1];
				A[j] = A[j] ^ A[j+1];
			}
		}
	}
	
	for(int i = 0; i < N; i++){
		cout << A[i] << "\n";
	}
	
}
