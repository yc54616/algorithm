#include <iostream>
#include <cmath>

using namespace std;

static int N, r, c, cnt;

void f(int size, int x, int y);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> r >> c;
    f(pow(2,N), 0, 0);
}

void f(int size, int x, int y){
    if(x == c && y == r){
        cout << cnt;
        return;
    }
    else if(x<= c && c < x+size && y<= r && r < y+size){
        int next = size / 2;
        f(next, x, y);
        f(next, x+next, y);
        f(next, x, y+next);
        f(next, x+next, y+next);
    }
    else{
        cnt += size*size;
    }

    


        

    
}

