#include <iostream>
using namespace std;

long long tree[4000004];

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

long long sum(int idx, int start, int end, int left, int right)
{
    if (start > right || left > end)
        return (0);
    
    if (start >= left && end <= right)
        return (tree[idx]);

    return sum(idx * 2, start, (start + end) / 2, left, right) + sum(idx * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, Q;
    cin >> N >> Q;

    for (int i = 0; i < Q; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
            update(1, 0, N - 1, b - 1, c);
        else
            cout << sum(1, 0, N - 1, b - 1, c - 1) << "\n";
    }
    return (0);
}