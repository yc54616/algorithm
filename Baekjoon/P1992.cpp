#include <iostream>
#include <string>

using namespace std;

static int N, arr[64][64];

void f(int size, int x, int y);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        string temp;
        cin >> temp;
        for(int j = 0; j < temp.size(); j++){
            arr[i][j] = temp[j] - '0';
        }
    }
    f(N, 0, 0);
}

void f(int size, int x, int y){
    int nextSize = size / 2;

    bool check = true;
    int cur = arr[x][y];
    for(int i = x; i < x+size; i++){
        for(int j = y; j < y+size; j++){
            if(cur != arr[i][j])
                check = false;
        }
    }

    if(check){
        cout << cur;
        return;
    }
    else{
        cout << "(";
        f(nextSize, x, y);
        f(nextSize, x, y+nextSize);
        f(nextSize, x+nextSize, y);
        f(nextSize, x+nextSize, y+nextSize);
        cout << ")";
    }
}
