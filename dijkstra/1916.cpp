#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
 
int N, M, start, finish;
int dist[1001];
vector <pair<int,int>> graph[1001];
queue<int> q;


int dijkstra(int start) {
    q.push(start);
    dist[start] = 0;
 
    while (!q.empty()) {
        int x = q.front();
        q.pop();
 
        for (int i = 0; i < graph[x].size(); i++) {
            int nx = graph[x][i].first;
            int cost = graph[x][i].second;
            if (dist[nx] == -1 || dist[x] + cost < dist[nx]) {
                dist[nx] = dist[x] + cost;
                if(nx != finish)
                    q.push(nx);
            }
        }
    }
    return dist[finish];
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dist, -1, sizeof(dist));
    
    cin >> N >> M;
 
    while (M--){
        int b, c, d;
        cin >> b >> c >> d;
        graph[b].push_back({c,d});
    }
    cin >> start >> finish;
 
    cout << dijkstra(start) << "\n";
 
    return 0;
}
