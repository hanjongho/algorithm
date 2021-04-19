#include <iostream>
using namespace std;

int N, M, virus_n = 0, cnt = -1, temp = 0, wall_sum = 0;
int MAP[11][11], MAP_c[11][11], visited[11][11] = {0,}, virus[11];
int dir_x[4] = {-1, 0, 1, 0};
int dir_y[4] = {0, -1, 0, 1};

void init()
{
    cin >> N >> M;
    for (int i = 0; i <= N + 1; i++)
    {
        for (int j = 0; j <= M + 1; j++)
        {
            if (i == 0 || i == N + 1 || j == 0 || j == M + 1)
                MAP[i][j] = MAP_c[i][j] = 1;
            else
            {
                cin >> MAP[i][j];
                if (MAP[i][j] == 2)
                    virus[virus_n++] = i * 10 + j;
                MAP_c[i][j] = MAP[i][j];
            }
        }
    }
}

void dfs(int x, int y) 
{
    for (int i = 0; i < 4; i++)
    {
        if (!MAP[x + dir_x[i]][y + dir_y[i]] && !visited[x + dir_x[i]][y + dir_y[i]])
        {
            visited[x + dir_x[i]][y + dir_y[i]] = 1;
            MAP[x + dir_x[i]][y + dir_y[i]] = 2;
            dfs(x + dir_x[i], y + dir_y[i]);
        }
    }
}

void solve()
{
    for (int wall_1 = 1; wall_1 <= N * M; wall_1++)
    {
        for (int wall_2 = wall_1 + 1; wall_2 <= N * M; wall_2++)
        {
            for (int wall_3 = wall_2 + 1; wall_3 <= N * M; wall_3++)
            {
                if (wall_1 % M == 0 && !MAP[wall_1 / M][M])
                {
                    MAP[wall_1 / M][M] = 1;
                    wall_sum++;
                }
                else if (!MAP[wall_1 / M + 1][wall_1 % M])
                {
                    MAP[wall_1 / M + 1][wall_1 % M] = 1;
                    wall_sum++;
                }

                if (wall_2 % M == 0 && !MAP[wall_2 / M][M])
                {
                    MAP[wall_2 / M][M] = 1;	
                    wall_sum++;
                }
                else if (!MAP[wall_2 / M + 1][wall_2 % M])
                {
                    MAP[wall_2 / M + 1][wall_2 % M] = 1;
                    wall_sum++;
                }	
				
                if (wall_3 % M == 0 && !MAP[wall_3 / M][M])
                {
                    MAP[wall_3 / M][M] = 1;
                    wall_sum++;
                }
                else if (!MAP[wall_3 / M + 1][wall_3 % M])
                {
                    MAP[wall_3 / M + 1][wall_3 % M] = 1;
                    wall_sum++;
                }

                if (wall_sum == 3)
				{
					for (int i = 0; i < virus_n; i++)
						dfs(virus[i] / 10, virus[i] % 10);
					for (int i = 0; i <= N + 1; i++)
					{
						for (int j = 0; j <= M + 1; j++)
						{
							if (!MAP[i][j])
								temp++;
							visited[i][j] = 0;
							MAP[i][j] = MAP_c[i][j];
						}
					}
					if (temp > cnt)
						cnt = temp;
					temp = 0;
				}
				else
				{
					for (int i = 0; i <= N + 1; i++)
					{
						for (int j = 0; j <= M + 1; j++)
						{
							visited[i][j] = 0;
							MAP[i][j] = MAP_c[i][j];
						}
					}
				}
				wall_sum = 0;
			}
		}
	}
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    init();
	solve();
    cout << cnt;
	return (0);
}