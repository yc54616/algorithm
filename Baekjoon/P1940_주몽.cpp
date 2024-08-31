#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> A(N, 0);
    
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    sort(A.begin(), A.begin()+N);
    
    int i = 0;
    int j = N - 1;
    int count = 0;
    
    while(i < j){
    	if(A[i] + A[j] == M){
    		count++;
    		i++;
    		j--;
		}
		else if(A[i] + A[j] < M){
			i++;
		}
		else{
			j--;
		}
		
	}
	cout << count << "\n";
    

}
