#include <iostream>

#define MAX_NM 100000

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    int num[MAX_NM + 1];
    int sumNum[MAX_NM + 1];
    for (int i = 0; i <= MAX_NM; i++)
        num[i] = 0;

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> num[i];

    for (int i = 1; i <= n; i++)
        sumNum[i] = sumNum[i - 1] + num[i];

    int start, end;
    for (int i = 0; i < m; i++)
    {
        cin >> start >> end;
        cout << sumNum[end] - sumNum[start - 1] << "\n";
    }
}