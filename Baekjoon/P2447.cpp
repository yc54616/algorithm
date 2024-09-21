#include <iostream>

using namespace std;

void f(int x1, int x2, int y1, int y2);

static bool arr[7000][7000] = {false, };

void f(int size, int x, int y);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    f(n, 0, 0);

    for(int i = 0; i < n;  i++){
        for(int j = 0; j <n ; j++){
            if(arr[i][j])
                cout << "*";
            else
                cout << " ";
        }
        cout << "\n";
    }
}

void f(int size, int x, int y){
    int nextSize = size/3;
    
    if(size == 1){
        arr[x][y] = true;
        return;
    }

    f(nextSize, x, y);
    f(nextSize, x+nextSize, y);
    f(nextSize, x+nextSize*2, y);

    f(nextSize, x, y+nextSize);

    f(nextSize, x+nextSize*2, y+nextSize);

    f(nextSize, x, y+nextSize*2);
    f(nextSize, x+nextSize, y+nextSize*2);
    f(nextSize, x+nextSize*2, y+nextSize*2);
}
