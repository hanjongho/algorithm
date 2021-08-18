#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int dir_x[4] = {1, -1, 0, 0};
int dir_y[4] = {0, 0, 1, -1};
int map[126][126], dist[126][126], visited[126][126];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int cnt = 1;
	while (1)
	{
		int N;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

		cin >> N;

		if (N == 0)
			break ;

		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> map[i][j];

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				dist[i][j] = 987654321;

		pq.push({map[0][0], {0, 0}});
		visited[0][0] = 1;
		while (!pq.empty())
		{
			int x = pq.top().second.first;
			int y = pq.top().second.second;
			int cost = pq.top().first;
			pq.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = x + dir_x[i];
				int ny = y + dir_y[i];
				int nextCost = cost + map[nx][ny];

                if (nx < 0 || nx > N - 1 || ny < 0 || ny > N - 1)
                    continue ;

                if (!visited[nx][ny] && dist[nx][ny] > nextCost)
                {
                    visited[nx][ny] = 1;
                    dist[nx][ny] = nextCost;
                    pq.push({nextCost, {nx, ny}});
                }
			}
		}
		cout << "Problem " << cnt++ << ": " << dist[N - 1][N - 1] << "\n";
	}

	return (0);
}