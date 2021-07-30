#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int T;
    cin >> T;
    while (T--)
    {
        int N, M, K, u, v1, c, d, ans = INF;
        int dist[101][10001] = {0, };
        priority_queue<pair<int, pair<int, int> > > pq;
        vector<pair<int, pair<int,int> > > v[101];

        cin >> N >> M >> K;
        for (int i = 0; i < K; i++)
        {
            cin >> u >> v1 >> c >> d;
            v[u].push_back({v1, {c, d}});
        }

        for (int i = 1; i <= N; i++)
            for (int j = 0; j <= M; j++)
                dist[i][j] = INF;
        
        dist[1][0] = 0;
        pq.push({dist[1][0], {1, 0}}); 
        while (!pq.empty())
        {
            int hour = pq.top().first * -1;
            int now = pq.top().second.first;
            int cost = pq.top().second.second;
            pq.pop();
            
            if (dist[now][cost] < hour)
                continue;
            
            for (int i = 0; i < v[now].size(); i++)
            {
                int next = v[now][i].first;
                int nextCost = cost + v[now][i].second.first;
                int nextHour = hour + v[now][i].second.second;
                
                if (nextCost <= M && dist[next][nextCost] > nextHour)
                {
                    // 시간을 단축시킬 수 있는 풀이
                    // for (int j = nextCost + 1; j <= M; j++)
                    // {
                    //     if (dist[next][j] <= nextHour)
                    //         break ;
                    //     dist[next][j] = nextHour;
                    // }
                    
                    dist[next][nextCost] = nextHour;
                    pq.push({nextHour * -1, {next, nextCost}});
                }
            }   
        }
        
        for (int i = 0; i <= M; i++)
            if (dist[N][i] < ans)
                ans = dist[N][i];
        
        if (ans == INF)
            cout << "Poor KCM" << "\n";
        else
            cout << ans << "\n";
    }
    return (0);
}