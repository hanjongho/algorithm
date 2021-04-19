#include <iostream>
using namespace std;

int N, M, maxV = -1, tmp;
int map[501][501] = {0,};
int dir_x[4] = {0, 0, 1, -1};
int dir_y[4] = {1, -1, 0, 0};

void dfs(int x, int y, int tx, int ty, int count, int total)
{
    if (count == 3)
    {
        maxV = max(maxV, total);
        return ;
    }
    
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dir_x[i];
        int ny = y + dir_y[i];

        if (nx < 1 || nx > N || ny < 1 || ny > M || (tx == nx && ty == ny))
            continue ;
        
        dfs(nx, ny, x, y, count + 1, total + map[nx][ny]);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> map[i][j];
    
    for (int i = 1; i <= N; i++)
       for (int j = 1; j <= M; j++)
        {
           dfs(i, j, 0, 0, 0, map[i][j]);
           
           if (i + dir_x[0] >= 1 && i + dir_x[0] <= N && j + dir_y[0] >= 1 &&  j + dir_y[0] <= M &&
                i + dir_x[1] >= 1 && i + dir_x[1] <= N && j + dir_y[1] >= 1 &&  j + dir_y[1] <= M &&
                i + dir_x[2] >= 1 && i + dir_x[2] <= N && j + dir_y[2] >= 1 &&  j + dir_y[2] <= M)
               tmp = map[i][j] + map[i + dir_x[0]][j + dir_y[0]] + map[i + dir_x[1]][j + dir_y[1]] + map[i + dir_x[2]][j + dir_y[2]];
           maxV = max(maxV, tmp);
           
           if (i + dir_x[0] >= 1 && i + dir_x[0] <= N && j + dir_y[0] >= 1 &&  j + dir_y[0] <=M &&
                i + dir_x[1] >= 1 && i + dir_x[1] <= N && j + dir_y[1] >= 1 &&  j + dir_y[1] <=M &&
                i + dir_x[3] >= 1 && i + dir_x[3] <= N && j + dir_y[3] >= 1 &&  j + dir_y[3] <=M)
               tmp = map[i][j] + map[i + dir_x[0]][j + dir_y[0]] + map[i + dir_x[1]][j + dir_y[1]] + map[i + dir_x[3]][j+dir_y[3]];
           maxV = max(maxV, tmp);
           
           if( i + dir_x[0] >= 1 && i + dir_x[0] <= N && j + dir_y[0] >= 1 &&  j + dir_y[0] <=M &&
                i + dir_x[3] >= 1 && i + dir_x[3] <= N && j + dir_y[3] >= 1 &&  j + dir_y[3] <=M &&
                i + dir_x[2] >= 1 && i + dir_x[2] <= N && j + dir_y[2] >= 1 &&  j + dir_y[2] <=M)
               tmp = map[i][j] + map[i + dir_x[0]][j + dir_y[0]] + map[i + dir_x[3]][j + dir_y[3]] + map[i + dir_x[2]][j + dir_y[2]];
           maxV = max(maxV, tmp);
           
           if( i + dir_x[3] >= 1 && i + dir_x[3] <= N && j + dir_y[3] >= 1 &&  j + dir_y[3] <=M &&
                i + dir_x[1] >= 1 && i + dir_x[1] <= N && j + dir_y[1] >= 1 &&  j + dir_y[1] <=M &&
                i + dir_x[2] >= 1 && i + dir_x[2] <= N && j + dir_y[2] >= 1 &&  j + dir_y[2] <=M)
               tmp = map[i][j] + map[i + dir_x[3]][j + dir_y[3]] + map[i + dir_x[1]][j + dir_y[1]] + map[i + dir_x[2]][j + dir_y[2]];
           maxV = max(maxV, tmp);
        }
    cout << maxV;
    return (0);
}