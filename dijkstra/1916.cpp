#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int> > v[1001];
priority_queue<pair<int, int>> pq;
int dist[1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M, start, end;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
    {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({b, c});
	}
	cin >> start >> end;

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

			if (nextCost < dist[next])
            {
				dist[next] = nextCost;
				pq.push({nextCost * -1, next});
			}
		}
	}
    
	cout << dist[end] << "\n";

	return (0);
}