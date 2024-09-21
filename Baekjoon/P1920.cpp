#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

static int N, M;
static vector<int> A;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    A.resize(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    cin >> M;
    for(int i = 0; i < M; i++){
        bool find = false;
        int target;
        cin >> target;
        int start = 0;
        int end = N - 1;

        while(start <= end){
            int mid = (start+end)/2;

            if(target < A[mid])
                end = mid - 1;
            else if (target > A[mid])
                start = mid + 1;
            else{
                find = true;
                break;
            }
                
        }
        cout << find << "\n";
    }
}