#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
    int t;
    cin >> t;
    
    while (t--)
    {
        int n, d, c;
        int dist[10001];
        memset(dist, 0, sizeof(dist));
        vector<pair<int, int> > v[10001];
        priority_queue<pair<int, int> > pq;
        cin >> n >> d >> c;
        for (int i = 0; i < d; i++)
        {
            int a, b, s;
            cin >> a >> b >> s;
            v[b].push_back({a, s});
        }

        for (int i = 1 ; i <= n; i++)
            dist[i] = 987654321;
        dist[c] = 0;
        pq.push({dist[c], c});
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

        int cnt = 0, sec = -1;
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] != 987654321)
            {
                cnt++;
                sec = max(sec, dist[i]);
            }
        }
        cout << cnt << " " << sec << "\n";
    }

	return (0);
}