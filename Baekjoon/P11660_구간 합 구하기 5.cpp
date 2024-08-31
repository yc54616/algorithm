#include <iostream>

#define MAX_N 1024

using namespace std;

int n, m;
int num[MAX_N + 1][MAX_N + 1];
int sumNum[MAX_N + 1][MAX_N + 1];
int x1, x2, y1, y2;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> num[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        sumNum[1][i] = sumNum[1][i - 1] + num[1][i];
        sumNum[i][1] = sumNum[i - 1][1] + num[i][1];
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            sumNum[i][j] = sumNum[i - 1][j] + sumNum[i][j - 1] - sumNum[i - 1][j - 1] + num[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        cin >> y1 >> x1 >> y2 >> x2;
        cout << sumNum[y2][x2] - sumNum[y1 - 1][x2] - sumNum[y2][x1 - 1] + sumNum[y1 - 1][x1 - 1] << "\n";
    }
}