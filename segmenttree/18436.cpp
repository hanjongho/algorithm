#include <iostream>
#include <vector>
using namespace std;

long long arr[100001];
pair<long long, long long> tree[400004];

pair<long long, long long> init(int idx, int start, int end)
{
    if (start == end)
    {
        if (arr[start] % 2 == 0)
            tree[idx] = {0, 1};
        else
            tree[idx] = {1, 0};
        return tree[idx];
    }
    pair<long long, long long> left = init(idx * 2, start, (start + end) / 2);
    pair<long long, long long> right = init(idx * 2 + 1, (start + end) / 2 + 1, end);
    tree[idx].first = left.first + right.first;
    tree[idx].second = left.second + right.second;
    return tree[idx];
}

void update(int idx, int start, int end, int findIdx, int changeValue)
{
    if (findIdx < start || findIdx > end)
        return ;

    if (start == end)
    {
        if (changeValue % 2 == 0)
            tree[idx] = {0, 1};
        else
            tree[idx] = {1, 0};
        return ;
    }

    update(idx * 2, start, (start + end) / 2, findIdx, changeValue);
    update(idx * 2 + 1, (start + end) / 2 + 1, end, findIdx, changeValue);

    tree[idx].first = tree[idx * 2].first + tree[idx * 2 + 1].first;
    tree[idx].second = tree[idx * 2].second + tree[idx * 2 + 1].second;    
}

pair<long long, long long> sum(int idx, int start, int end, int left, int right)
{
    if (right < start || left > end)
        return {0, 0};
    
    if (start >= left && end <= right)
        return tree[idx];

    pair<long long, long long> left_ = sum(idx * 2, start, (start + end) / 2, left, right);
    pair<long long, long long> right_ = sum(idx * 2 + 1, (start + end) / 2 + 1, end, left, right);
    return {left_.first + right_.first, left_.second + right_.second};
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    
    init(1, 0, N - 1);

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
            update(1, 0, N - 1, b - 1, c);
        else if (a == 2)
            cout << sum(1, 0, N - 1, b - 1, c - 1).second << "\n";
        else if (a == 3)
            cout << sum(1, 0, N - 1, b - 1, c - 1).first << "\n";
    }

    return (0);
}