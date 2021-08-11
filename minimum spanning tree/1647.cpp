#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, pair<int, int> > > v;
int N, M, ans = 0;
int parent[100001];

int findParent(int x)
{
    if (x == parent[x])
        return x;
    return parent[x] = findParent(parent[x]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        parent[i] = i;

    for (int i = 0; i < M; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;
        v.push_back({C, {A, B}});
    }

    sort(v.begin(), v.end());

    int connected = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (connected == N - 2)
            break ;
        
        int startParent = findParent(v[i].second.first);
        int endParent = findParent(v[i].second.second);
        if (startParent != endParent)
        {
            if (startParent < endParent)
                parent[endParent] = findParent(startParent);
            else
                parent[startParent] = findParent(endParent);
            connected++;
            ans += v[i].first;
        }
    }

    cout << ans << "\n";

    return (0);
}