#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M, A, B, C, s, e, left = 0, right = 0,MAX = -1;
int visited[10001];
vector<pair<int, int> > land[10001];

int bfs(int mid)
{
	queue <int> q;
	q.push(s);
	visited[s] = 1;
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		if (now == e)
			return (1);
		for (int i = 0; i < land[now].size(); i++)
		{
			int end = land[now][i].first;
			int weight = land[now][i].second;
			if (!visited[end] && mid <= weight)
			{
				visited[end] = 1;
				q.push(end); 
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
	cin >> s >> e;
	int left, right;
	right = MAX;
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