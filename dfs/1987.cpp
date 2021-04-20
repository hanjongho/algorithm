#include <iostream>
using namespace std;

int R, C, usedAlphabet[26], ans = 0;
int dir_x[4] = {0, 0, 1, -1};
int dir_y[4] = {1, -1, 0, 0};
string board[21];

void dfs(int x, int y, int cnt)
{
    if (cnt > ans)
        ans = cnt;
    usedAlphabet[board[x][y] - 'A'] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dir_x[i];
        int ny = y + dir_y[i];
        if (nx < 0 || ny < 0 || nx > R - 1 || ny > C - 1)
            continue;
        if (!usedAlphabet[board[nx][ny] - 'A'])
        {
            dfs(nx, ny, cnt + 1);
            usedAlphabet[board[nx][ny] - 'A'] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> R >> C;
    for (int i = 0; i < R; i++)
        cin >> board[i];
    dfs(0, 0, 1);
	cout << ans << "\n";
    return (0);
}