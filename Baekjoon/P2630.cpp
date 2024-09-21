#include <iostream>

using namespace std;

static int N;
static int arr[128][128];
static int one, zero;

void f(int size, int x, int y);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }
    
    f(N, 0, 0);

    cout << zero << "\n" << one;
}

void f(int size, int x, int y){
    int nextSize = size/2;

    bool allSame = true;
    int cur = arr[x][y];

    for(int i = x; i < x+size; i++){
        for(int j = y; j < y+size; j++){
            if(cur != arr[i][j]){
                allSame = false;
            }
        }
    }

    if(allSame == false){
        f(nextSize, x, y);
        f(nextSize, x+nextSize, y);
        f(nextSize, x, y+nextSize);
        f(nextSize, x+nextSize, y+nextSize);
    }
    else{
        if(cur){
            one++;
        }
        else{
            zero++;
        }
        return;
    }   
}