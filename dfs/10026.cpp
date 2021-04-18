#include <iostream>
#include <string.h>
using namespace std;

int N, ans = 0;
int visited[101][101];
int dirX[4] = {-1, 0, 1, 0};
int dirY[4] = {0, 1, 0, -1};
char map[101][101];

void changeMapAndReset(int N)
{
    memset(visited, 0, sizeof(visited));
    ans = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (map[i][j] == 'G')
                map[i][j] = 'R';
}

void dfs(int x, int y, char color)
{
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dirX[i];
        int ny = y + dirY[i];
        if (nx < 0 || nx > N - 1 || ny < 0 || ny > N - 1)
            continue;
        if (!visited[nx][ny] && map[nx][ny] == color)
            dfs(nx, ny, color);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> map[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (!visited[i][j])
            {
                dfs(i, j, map[i][j]);
                ans++;
            }
    cout << ans << " ";
    changeMapAndReset(N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (!visited[i][j])
            {
                dfs(i, j, map[i][j]);
                ans++;
            }
    cout << ans;
    return (0);
}