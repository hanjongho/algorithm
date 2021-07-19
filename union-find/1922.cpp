#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, a, b, c, ans = 0;
int parent[1001];
pair<pair<int,int>, int> v[100001];

bool cmp(pair<pair<int,int>, int> v1, pair<pair<int,int>, int> v2) 
{
    return v1.second < v2.second;
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
    
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        parent[i] = i;
    
    for (int i = 0; i < M; i++)
	{
        cin >> a >> b >> c;
        v[i].first.first = a;
        v[i].first.second = b;
        v[i].second = c;
    }

    sort(v, v + M, cmp);
    
    for (int i = 0; i < M; i++)
	{
        if (findParent(v[i].first.first) != findParent(v[i].first.second))
		{
            a = findParent(v[i].first.first);
            b = findParent(v[i].first.second);

            if (a < b)
                parent[b] = a;
            else
                parent[a] = b;
                
            ans += v[i].second;
        }
    }

    cout << ans << "\n";
    
    return (0);
}