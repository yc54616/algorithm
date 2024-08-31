#include <iostream>

using namespace std;

int main()
{
    int n, num, max = 0, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        sum += num;
        if (num > max)
            max = num;
    }
    cout << sum / (double)max * 100.0 / n;
}