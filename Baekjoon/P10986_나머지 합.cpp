#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long n, m, result = 0;
    cin >> n >> m;
    vector<long> num(n + 1, 0);
    vector<long> sumNum(n + 1, 0);
    vector<long> modNum(n + 1, 0);
    vector<long> countNum(n + 1, 0);

    for (int i = 1; i <= n; i++)
        cin >> num[i];

    for (int i = 1; i <= n; i++)
        sumNum[i] = sumNum[i - 1] + num[i];

    for (int i = 1; i <= n; i++)
    {
        modNum[i] = sumNum[i] % m;
        if (modNum[i] == 0)
            result++;
        countNum[modNum[i]]++;
    }

    for (int i = 0; i <= n; i++)
    {
        if (countNum[i] >= 2)
            result += (countNum[i] * (countNum[i] - 1)) / 2;
    }
    cout << result << "\n";
}