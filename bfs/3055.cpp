#include <iostream>
#include <queue>
using namespace std;

queue< pair<pair<char, int>, pair<int, int> > > q;
char map[51][51];
int R, C, bieber_x, bieber_y, water_x, water_y, end_x, end_y;
int dir_x[4] = {0, 0, 1, -1};
int dir_y[4] = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'S')
            {
                bieber_x = i;
                bieber_y = j;
            }
            else if (map[i][j] == '*')
            {
                water_x = i;
                water_y = j;
                q.push({{'*', 0}, {water_x, water_y}});
            }
            else if (map[i][j] == 'D')
            {
                end_x = i;
                end_y = j;
            }
        }
    }

    q.push({{'S', 0}, {bieber_x, bieber_y}});

    while (!q.empty())
    {
        char value = q.front().first.first;
        int second = q.front().first.second;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir_x[i];
            int ny = y + dir_y[i];
            if (value == '*')
            {
                if (map[nx][ny] == '.' || map[nx][ny] == 'S')
                {
                    map[nx][ny] = '*';
                    q.push({{'*', second + 1}, {nx, ny}});
                }
            }
            else if (value == 'S')
            {
                if (map[nx][ny] == 'D')
                {
                    cout << second + 1 << "\n";
                    return (0);
                }
                if (map[nx][ny] == '.')
                {
                    map[nx][ny] = 'S';
                    q.push({{'S', second + 1}, {nx, ny}});
                }
            }
        }
    }
    cout << "KAKTUS\n";
    return (0);
}