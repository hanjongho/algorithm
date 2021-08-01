#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, max_ans = 0, min_ans = 0;
int parent[1001];
vector<pair<int,pair<int,int> > > v;

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
    
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    if (a3 == 0)
    {
        max_ans++;
        min_ans++;
    }
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
            if (v[i].first == 0)
                max_ans++;
            connected++;
        }
    }

    for (int i = 1; i <= N; i++)
        parent[i] = i;

    connected = 0;
    for (int i = v.size() - 1; i > -1; i--)
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
            if (v[i].first == 0)
                min_ans++;
            connected++;
        }
    }

    max_ans *= max_ans;
    min_ans *= min_ans;

    cout << max_ans - min_ans << "\n";

    return (0);
}