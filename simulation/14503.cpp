#include <iostream>
using namespace std;

int N, M, r, c, dir, ans = 0;
int dir_x[4] = {-1, 0, 1, 0};
int dir_y[4] = {0, 1, 0, -1};
int map[51][51];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> r >> c >> dir;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> map[i][j];

    while (1)
    {
        int allClear = 1;
        if (map[r][c] == 0)
        {
            map[r][c] = 2;
            ans++;
        }
        for (int i = 0; i < 4; i++)
        {
            dir = (dir == 0) ? 3 : dir - 1;
            int nr = r + dir_x[dir];
            int nc = c + dir_y[dir];
            if (map[nr][nc] == 0)
            {
                r = nr;
                c = nc;
                allClear = 0;
                break ;
            }
        }
        if (allClear)
        {
            int tmp_dir = (dir <= 1) ? dir + 2 : dir - 2;
            r = r + dir_x[tmp_dir];
            c = c + dir_y[tmp_dir];
            if (map[r][c] == 1)
                break ;
        }
    }
    cout << ans;
    return (0);
}