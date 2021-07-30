#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;

int N, M, X;
int dist[1001];
priority_queue<pair<int, int> > pq;
vector<pair<int, int> > v[1001];

void dijkstra(int start)
{
	memset(dist, 0, sizeof(dist));

	for (int i = 1; i <= N; i++)
		dist[i] = 987654321;

	dist[start] = 0;
	pq.push({dist[start], start});
	while (!pq.empty())
	{
		int cost = pq.top().first * -1;
		int now = pq.top().second;
		pq.pop();

		if (dist[now] < cost)
			continue ;
		
		for (int i = 0; i < v[now].size(); i++)
		{
			int next = v[now][i].first;
			int nextCost = cost + v[now][i].second;
			
			if (dist[next] > nextCost)
			{
				dist[next] = nextCost;
				pq.push({dist[next] * -1, next});
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M >> X;
	int cost[1001];
	
	for (int i = 0; i < M; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;
		v[A].push_back({B, C});
	}

	for (int i = 1; i <= N; i++)
	{
		if (i == X)
			continue ;
		dijkstra(i);
		cost[i] = dist[X];
		
	}
	dijkstra(X);
	for (int i = 1; i <= N; i++)
		cost[i] += dist[i];

	int ans = -1;
	for (int i = 1; i <= N; i++)
	{
		if (i == X)
			continue;
		if (ans < cost[i])
			ans = cost[i];
	}
	cout << ans << "\n";

	return (0);
}