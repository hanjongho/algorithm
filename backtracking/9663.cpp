#include <iostream>
using namespace std;

int N, ans = 0;
int map[16][16];

int positionCheck(int x, int y)
{
    int i, j;

    i = x;
    j = y;
    while (i >= 0)
        if (map[i--][y])
            return (0);

    i = x;
    j = y;
    while (i >= 0 && j >= 0)
        if (map[i--][j--])
            return (0);

    i = x;
    j = y;
    while (i >= 0 && j < N)
        if (map[i--][j++])
            return (0);
    return (1);
}

void dfs(int idx)
{
    if (idx == N)
    {
        ans++;
        return ;
    }

    for (int i = 0; i < N; i++)
    {
        if (positionCheck(idx, i))
        {
            map[idx][i] = 1;
            dfs(idx + 1);
            map[idx][i] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;

    dfs(0);

    cout << ans << "\n";
    
    return (0);
}