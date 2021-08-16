#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

int parent[200001];

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

    while (1)
    {
        int m, n, ans = 0, total = 0;
        memset(parent, 0, sizeof(int) * 200001);
        vector<pair<int, pair<int, int> > > v;
        cin >> m >> n;
        
        if (m == 0 && n == 0)
            break ;
        
        for (int i = 0; i < m; i++)
            parent[i] = i;

        for (int i = 0; i < n; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            total += z;
            v.push_back({z, {x, y}});
        }

        sort(v.begin(), v.end());

        int connected = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (connected == m - 1)
                break ;
            int startParent = findParent(v[i].second.first);
            int endParent = findParent(v[i].second.second);

            if (startParent != endParent)
            {
                if (startParent < endParent)
                    parent[endParent] = findParent(startParent);
                else
                    parent[startParent] = findParent(endParent);
                ans += v[i].first;
                connected++;
            }
        }
        cout << total - ans << "\n";
    }
    
    return (0);
}