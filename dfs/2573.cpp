#include <iostream>
#include <queue>
using namespace std;

int N, M, ans, result = 0, tmp = 0;
int map[301][301], visited[301][301];
int dir_x[4] = {0, 0, 1, -1};
int dir_y[4] = {1, -1, 0, 0};

void melt()
{
	queue <pair<int, int> > q;
	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < M; y++)
		{
			if (map[x][y] != 0)
			{
				for (int i = 0; i < 4; i++)
				{
					int nx = x + dir_x[i];
					int ny = y + dir_y[i];
					if (nx < 0 || nx > N - 1 || ny < 0 || ny > M - 1)
						continue ;
					if (map[nx][ny] == 0 && map[x][y] != 0)
						q.push(make_pair(x, y));
				}
			}
		}
	}
	while (!q.empty())
	{
		pair<int, int> t = q.front();
		q.pop();
		if (map[t.first][t.second] > 0)
			map[t.first][t.second]--;
	}

}

void dfs(int x, int y)
{
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dir_x[i];
		int ny = y + dir_y[i];
		if (nx < 0 || nx > N - 1 || ny < 0 || ny > M - 1)
			continue ;
		if (!visited[nx][ny] && map[nx][ny] != 0)
			dfs(nx, ny);
	}
}

int map_empty()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (map[i][j] != 0)
				return (0);
	return (1);
}

void init_visited()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			visited[i][j] = 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	
	while (1)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (!visited[i][j] && map[i][j] != 0)
				{
					dfs(i, j);
					ans++;
				}
			}
		}
		if (ans > 1)
			break ;
		result++;
		melt();
		tmp = map_empty();
		if (tmp)
			break ;
		init_visited();
		ans = 0;
	}
	if (tmp)
		cout << "0\n";
	else
		cout << result << "\n";
    return (0);
}