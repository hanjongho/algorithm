#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long tree[8004];
vector<pair<int, int> > v;

long long query(int idx, int start, int end, int left, int right)
{
    if (right < start || left > end)
        return (0);
    
    if (start >= left && end <= right)
        return tree[idx];

    return query(idx * 2, start, (start + end) / 2, left, right) + query(idx * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void update(int idx, int start, int end, int findIdx, int changeValue)
{
    if (findIdx < start || findIdx > end)
        return ;
    
    if (start == end)
    {
        tree[idx] += changeValue;
        return ;   
    }
    update(idx * 2, start, (start + end) / 2, findIdx, changeValue);
    update(idx * 2 + 1, (start + end) / 2 + 1, end, findIdx, changeValue);
    tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());

    long long result = 0;
    for (int i = 0; i < v.size(); i++)
    {
        result += query(1, 0, N - 1, v[i].second, N - 1);
        update(1, 0, N - 1, v[i].second - 1, 1);
    }

    cout << result << "\n";
    
    return (0);
}
