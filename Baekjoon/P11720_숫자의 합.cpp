#include <iostream>

using namespace std;

int main()
{
    int n, sum = 0;
    string str;
    cin >> n;
    cin >> str;
    for (int i = 0; i < n; i++)
    {
        sum += str[i] - '0';
    }
    cout << sum << "\n";
}
