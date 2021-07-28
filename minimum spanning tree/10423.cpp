#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, K, ans = 0;
int parent[1001], ele[1001];
vector<pair<int, pair<int, int> > > v;

int isSameEle(int start, int end)
{
    if (ele[start] != 0 && ele[end] != 0)
        return (1);
    return (0);
}

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

    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++)
        parent[i] = i;

    for (int i = 0; i < K; i++)
    {
        int e;
        cin >> e;
        ele[e] = e;
    }

    for (int i = 0; i < M; i++)
    {
        int u, v1, w;
        cin >> u >> v1 >> w;
        v.push_back({w, {u, v1}});
    }

    sort(v.begin(), v.end());

    int connected = K - 1;
    for (int i = 0; i < v.size(); i++)
    {
        if (N - 1 == connected)
            break ;

        int startParent = findParent(v[i].second.first);
        int endParent = findParent(v[i].second.second);

        if ((startParent != endParent) && !isSameEle(startParent, endParent))
        {
            if (startParent < endParent)
                parent[endParent] = findParent(startParent);
            else
                parent[startParent] = findParent(endParent);

            if (ele[startParent] != 0)
                ele[endParent] = ele[startParent];
            if (ele[endParent] != 0)
                ele[startParent] = ele[endParent];
            connected++;
            ans += v[i].first; 
        }
    }
    cout << ans << "\n";

    return (0);
}