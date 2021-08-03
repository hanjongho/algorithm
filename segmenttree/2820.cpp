#include <iostream>
#include <vector>
#define MAX 500001
using namespace std;

int n, m, l[MAX], r[MAX], cnt = 0;
long long tree[MAX * 4], lazy[MAX * 4], salary[MAX], salary_[MAX];
vector<vector<int>> p;

void dfs(int now) // L[i]는 내 번호, R[i]는 내 트리 기준 맨 마지막 인덱스
{
    l[now] = ++cnt;
    for (int next : p[now])
        dfs(next);
    r[now] = cnt;
}

long long init(int idx, int start, int end)
{
    if (start == end)
        return tree[idx] = salary_[start];

    return tree[idx] = init(idx * 2, start, (start + end) / 2) +  init(idx * 2 + 1, (start + end) / 2 + 1, end);
}

void update_lazy(int idx, int start, int end)
{
    if (lazy[idx])
    {
        tree[idx] += lazy[idx] * (end - start + 1);
        if (start != end)
        {
            lazy[idx * 2] += lazy[idx];
            lazy[idx * 2 + 1] += lazy[idx];
        }
        lazy[idx] = 0;
    }
}

void update(int idx, int start, int end, int left, int right, long long changeValue)
{
    update_lazy(idx, start, end);

    if (right < start || end < left)
        return ;

    if (left <= start && end <= right)
    {
        tree[idx] += changeValue;
        if (start != end)
        {
            lazy[idx * 2] += changeValue;
            lazy[idx * 2 + 1] += changeValue;
        }
        return ;
    }
    update(idx * 2, start, (start + end) / 2, left, right, changeValue);
    update(idx * 2 + 1, (start + end) / 2 + 1, end, left, right, changeValue);
}

long long query(int idx, int start, int end, int findIdx)
{
    update_lazy(idx, start, end);
    
    if (findIdx < start || end < findIdx)
        return (0);

    if (start == end)
        return tree[idx];
    
    return query(idx * 2, start, (start + end) / 2, findIdx) + query(idx * 2 + 1, (start + end) / 2 + 1, end, findIdx);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> salary[1];
    p.resize(n + 1);

    int x, y;
    for (int i = 2; i <= n; i++)
    { // p[i]에는 아래 얘들이 들어있음
        cin >> salary[i] >> x;
        p[x].push_back(i);
    }

    dfs(1);
    for (int i = 1; i <= n; i++)
        salary_[l[i]] = salary[i];

    init(1, 1, n);
    
    for (int i = 0; i < m; i++)
    {
        char c;
        cin >> c;
        if (c == 'p')
        {
            cin >> x >> y;
            update(1, 1, n, l[x] + 1, r[x], y);
        }
        else if (c == 'u')
        {
            cin >> x;
            cout << query(1, 1, n, l[x]) << "\n";
        }
    }
}
