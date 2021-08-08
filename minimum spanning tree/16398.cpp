#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
long long ans = 0;
int parent[1001];
vector<pair<int, pair<int, int> > > v;

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

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
        parent[i] = i;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int tmp;
            cin >> tmp;
            if (j > i)
                v.push_back({tmp, {i, j}});
        }
    }
    
    sort(v.begin(), v.end());

    int connected = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (N - 1 == connected)
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