#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int dist[801];
int N, E, v1, v2, v1_ans, v2_ans, v3_ans, v4_ans;
vector <pair<int, int> > v[801];
priority_queue <pair<int, int> > q;

void dijkstra(int x)
{
    for (int i = 1; i <= N; i++)
        dist[i] = INF;
    dist[x] = 0;
    q.push({dist[x], x});
    while (!q.empty())
    {
        int cost = q.top().first * -1;
        int now = q.top().second;
        q.pop();

        if (dist[now] < cost)
            continue ;

        for (int i = 0; i < v[now].size(); i++)
        {
            int next = v[now][i].first;
            int nextCost = cost + v[now][i].second;

            if (nextCost < dist[next])
            {
				dist[next] = nextCost;
				q.push({nextCost * -1, next});
			}
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> E;

    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    cin >> v1 >> v2;

    dijkstra(1);
    v1_ans = dist[v1];
    v3_ans = dist[v2];
    dijkstra(v1);
    int dist1 = dist[v2];

    dijkstra(v2);
    int dist2 = dist[v1];
    dijkstra(v2);
    v2_ans = dist[N];
    dijkstra(v1);
    v4_ans = dist[N];
    
    if ((v1_ans == INF || v2_ans == INF) && (v3_ans == INF || v4_ans == INF) || (dist1 == INF && dist2 == INF))
        cout << "-1\n";
    else
        cout << min(v1_ans + dist1 + v2_ans, v3_ans + dist2 + v4_ans) << "\n";

    return (0);
}