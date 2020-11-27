#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M, A, B, C, p1, p2, MAX = -1;
int visited[10001];
vector<pair<int, int> > land[10001];

int bfs(int mid)
{
	queue <int> q;
	q.push(p1);
	visited[p1] = 1;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		if (now == p2)
			return (1);
		for (int i = 0; i < land[now].size(); i++)
		{
			B = land[now][i].first;
			C = land[now][i].second;
			if (!visited[B] && mid <= C)
			{
				visited[now] = 1;
				q.push(B);
			}
		}
	}
	return (0);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;
		land[A].push_back(make_pair(B,C));
		land[B].push_back(make_pair(A,C));
		MAX = max(MAX, C);
	}
	cin >> p1 >> p2;
	int left = 0, right = MAX;
	while (left <= right)
	{
		memset(visited, 0, sizeof(visited));
		int mid = (left + right) / 2;
		if (bfs(mid))
			left = mid + 1;
		else
			right = mid - 1;
	}
	cout << right;
	return (0);
}