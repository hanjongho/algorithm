#include <iostream>
using namespace std;

long long arr[1000001], tree[4000004];

long long init(int idx, int start, int end)
{
    if (start == end)
        return tree[idx] = arr[start];

    return tree[idx] = (init(idx * 2, start, (start + end) / 2) * init(idx * 2 + 1, (start + end) / 2 + 1, end)) % 1000000007;
}

long long multiply(int idx, int start, int end, int left, int right)
{
    if (right < start || left > end)
        return (1);
    
    if (start >= left && right >= end)
        return tree[idx];

    return (multiply(idx * 2, start, (start + end) / 2, left, right) * multiply(idx * 2 + 1, (start + end) / 2 + 1, end, left, right) % 1000000007);
}

void update(int idx, int start, int end, int findIdx, int changeValue)
{
    if (findIdx < start || findIdx > end)
        return ;

    if (start == end)
    {
        tree[idx] = changeValue;
        return ;
    }
    update(idx * 2, start, (start + end) / 2, findIdx, changeValue);
    update(idx * 2 + 1, (start + end) / 2 + 1, end, findIdx, changeValue);
    tree[idx] = (tree[idx * 2] * tree[idx * 2 + 1]) % 1000000007;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    init(1, 0, N - 1);

    for (int i = 0; i < M + K; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
            update(1, 0, N - 1, b - 1, c);
        else
            cout << multiply(1, 0, N - 1, b - 1, c - 1) << "\n";
    }

    return (0);
}