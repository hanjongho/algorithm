#include <iostream>
using namespace std;

long long arr[100001], tree[400004];

long long init(int idx, int start, int end)
{
    if (start == end)
        return tree[idx] = arr[start];

    return tree[idx] = min(init(idx * 2, start, (start + end) / 2), init(idx * 2 + 1, (start + end) / 2 + 1, end));
}

long long getMin(int idx, int start, int end, int left, int right)
{
    if (start > right || left > end)
        return (2e9);
    
    if (start >= left && end <= right)
        return tree[idx];

    return min(getMin(idx * 2, start, (start + end) / 2, left, right), getMin(idx * 2 + 1, (start + end) / 2 + 1, end, left, right));
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
    tree[idx] = min(tree[idx * 2], tree[idx * 2 + 1]);
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
            cout << getMin(1, 0, N - 1, b - 1, c - 1) << "\n";
    }

    return (0);
}