#include <iostream>
#include <queue>
using namespace std;

queue <pair<pair<int, int>, pair<int, int> > > q;
int N, M, H;
int dir_x[6] = {1, -1, 0, 0, 0, 0}; 
int dir_y[6] = {0, 0, -1, 1, 0, 0};
int dir_h[6] = {0, 0, 0, 0, 1, -1};
int box[101][101][101];

int endCheck()
{
    for (int k = 0; k < H; k++)
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                if (box[k][i][j] == 0) 
                    return (0);
    return (1);
}

void bfs()
{
    int t;
    while (!q.empty())
    {	
        int h = q.front().first.first;
        int x = q.front().first.second;
        int y = q.front().second.first;
        t = q.front().second.second;
        q.pop();
		
        for (int i = 0; i < 6; i++)
        {
            int nh = h + dir_h[i];
            int nx = x + dir_x[i];
            int ny = y + dir_y[i];
            if (nx < 0 || nx > M - 1 || ny < 0 || ny > N - 1 || nh < 0 || nh > H - 1)
                continue ;
            if (box[nh][nx][ny] == 0)
            {
                box[nh][nx][ny] = 1;
                q.push(make_pair(make_pair(nh, nx), make_pair(ny, t + 1)));
            }
        }
    }
    if (!endCheck())
        cout << "-1\n";
    else
        cout << t << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> H;
    for (int k = 0; k < H; k++)
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
            {
                cin >> box[k][i][j];
                if (box[k][i][j] == 1)
                    q.push(make_pair(make_pair(k, i), make_pair(j, 0)));
            }
            
    bfs();

    return (0);
} 