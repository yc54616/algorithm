#include <iostream>

using namespace std;

void f(int i, int j, int x, int y);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    f(0, 3, 0, 3);
}  

void f(int i, int j, int x, int y){
    if(j - i == 3 && y - x == 3){
        cout << "***\n";
        cout << "* *\n";
        cout << "***\n";
        return;
    }

    f(i, j/3, x, y/3);
    f(j/3, (j/3)*2, x, y/3);
    f((j/3)*2, j, x, y/3);
    f(i, j/3, y/3, (y/3)*2);

    f((j/3)*2, j, y/3, (y/3)*2);
    f(i, j/3, (y/3)*2, y);
    f(j/3, (j/3)*2, (y/3)*2, y);
    f((j/3)*2, j, (y/3)*2, y);
}

// i - j == 3 && x - y == 3
// 수학의 귀납법과 같다

// []답1 []답2
// 수열문제 -> 절반쪼개기