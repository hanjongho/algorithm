#include <iostream>
#include <queue>
using namespace std;

priority_queue <pair<int,int> > pq;
int dist[1001], save[1001];
vector<pair<int,int> > v[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, start, end;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }
    cin >> start >> end;
    
    for (int i = 1; i <= n; i++)
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
                save[next] = now;
                pq.push({dist[next] * -1, next});
            }
        }
    }

    cout << dist[end] << "\n";

    vector<int> route;
    int node = end;
    while (node)
    {
        route.push_back(node);
        node = save[node];
    }
    cout << route.size() << "\n";
    for (int i = route.size() - 1; i >= 0; i--)
        cout << route[i] << " ";
    cout << "\n";
    return (0);
}