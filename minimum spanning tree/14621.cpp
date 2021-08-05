#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, ans = 0;
int parent[1001], kind[1001];

int findParent(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = findParent(parent[x]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector<pair<int, pair<int,int> > > v1;

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        char c;
        cin >> c;
        if (c == 'M')
            kind[i] = 1;
        else
            kind[i] = 0;
    }

    for (int i = 1; i <= N; i++)
        parent[i] = i;
        
    for (int i = 0; i < M; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        v1.push_back({d, {u, v}});
    }
    sort(v1.begin(), v1.end());
    
    int connected = 0;
    for (int i = 0; i < v1.size(); i++)
    {
        if (N - 1 == connected)
            break ;

        int startParent = findParent(parent[v1[i].second.first]);
        int endParent = findParent(parent[v1[i].second.second]);

        if (startParent != endParent && (kind[v1[i].second.first] != kind[v1[i].second.second]))
        {
            if (startParent < endParent)
                parent[endParent] = findParent(parent[startParent]);
            else
                parent[startParent] = findParent(parent[endParent]);
            connected++;
            ans += v1[i].first;
        }
    }
    if (N - 1 != connected)
        ans = -1;

    cout << ans << "\n";

    return (0);
}