#include <iostream>
#include <vector>
using namespace std;

long long arr[100001], tree[400004];

long long init(int idx, int start, int end)
{
    if (start == end)
        return tree[idx] = start;

    if (arr[init(idx * 2, start, (start + end) / 2)] <= arr[init(idx * 2 + 1,(start + end) / 2 + 1, end)])
        return tree[idx] = tree[idx * 2];
    else
        return tree[idx] = tree[idx * 2 + 1];
}

long long update(int idx, int start, int end, int findIdx)
{
    if (findIdx < start || findIdx > end || start == end)
        return tree[idx];
        
    if (arr[update(idx * 2, start, (start + end) / 2, findIdx)] <= arr[update(idx * 2 + 1, (start + end) / 2 + 1, end, findIdx)])
        return tree[idx] = tree[idx * 2];
    else
        return tree[idx] = tree[idx * 2 + 1];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N;

    for(int i = 0; i < N; i++)
        cin >> arr[i];

    init(1, 0, N - 1);
    cin >> M;
    for(int i = 0; i < M; i++)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            int b, c;
            cin >> b >> c;
            arr[b - 1] = c;
            update(1, 0, N - 1, b - 1);
        }
        else
            cout << tree[1] + 1 << "\n";
    }
}