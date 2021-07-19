#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long tree[2000001];
long long ans = 0;
pair<int, int> b[500001];

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
    tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}

long long sum(int idx, int start, int end, int left, int right) 
{
    if (start > right || end < left)
        return (0);

    if (start >= left && end <= right) 
        return tree[idx];

    return sum(idx * 2, start, (start + end) / 2, left, right) + sum(2 * idx + 1, (start + end) / 2 + 1, end, left, right);
}

int main() 
{
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) 
    {
        int num;
        cin >> num;
        b[i] = {num, i};
    }

    sort(b, b + N);

    for (int i = 0; i < N; i++)
    {
        int findIdx = b[i].second;
        ans += sum(1, 0, N - 1, findIdx + 1, N - 1);
        cout << sum(1, 0, N - 1, findIdx + 1, N - 1) << " ";
        update(1, 0, N - 1, findIdx, 1);
    }

    cout << ans << "\n";

    return (0);
}