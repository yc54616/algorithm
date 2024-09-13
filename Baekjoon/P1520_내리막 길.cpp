#include <iostream>

using namespace std;

static int dx[4] = {1, 0, -1, 0};
static int dy[4] = {0, -1, 0, 1};
static int N, M;
static int A[501][501];
static int D[501][501];

int DFS(int i, int j);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> A[i][j];
            D[i][j] = -1;
        }
    }

    DFS(1, 1);

    cout << D[1][1];
}

int DFS(int x, int y)
{

    if (x == M && y == N)
        return 1;
    if (D[x][y] != -1)
        return D[x][y];

    D[x][y] = 0;
    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];

        if (xx < 1 || yy < 1 || xx > M || yy > N)
            continue;

        if (A[x][y] > A[xx][yy])
        {
            D[x][y] += DFS(xx, yy);
        }
    }

    return D[x][y];
}