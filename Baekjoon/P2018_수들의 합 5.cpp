#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int count = 1;
    int startIndex = 1;
    int endIndex = 1;
    int sum = 1;

    while(endIndex != n){
        if(sum == n){
            count++;
            endIndex++;
            sum = sum + endIndex;
        }
        else if(sum > n){
            sum = sum - startIndex;
            startIndex++;
        }
        else{
            endIndex++;
            sum = sum + endIndex;
        }
    }

    cout << count << "\n";
}