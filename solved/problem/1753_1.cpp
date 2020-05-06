#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int V, E, K, u, w, v, INF = 987654321;

vector<pair<int, int>> a[20001];

vector<int> Dijkstra(int vertex, int start)
{
    vector<int> d(vertex, INF);
    d[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    while (!pq.empty()) {
        int distance = -pq.top().first;
        int current = pq.top().second;
        pq.pop();
        if (d[current] < distance)continue;
        for (int i = 0; i < a[current].size(); ++i) {
            int next = a[current][i].first;
            if (d[next] > a[current][i].second + distance) {
                d[next] = a[current][i].second + distance;
                pq.push(make_pair(-(a[current][i].second + distance), next));
            }
        }
    }
    return d;
}

int main()
{
    cin >> V >> E >> K;
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        a[u].push_back(make_pair(v,w));
    }
    
    vector<int>dist = Dijkstra(V+1, K);
    
    for (int i = 1; i <= V; ++i) {
        if (dist[i] == INF)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }
    return 0;
}
