#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long arr[100001], minTree[400004], maxTree[400004];

long long minInit(int idx, int start, int end)
{
    if (start == end)
        return minTree[idx] = arr[start];

    return minTree[idx] = min(minInit(idx * 2, start, (start + end) / 2), minInit(idx * 2 + 1, (start + end) / 2 + 1, end));
}

long long maxInit(int idx, int start, int end)
{
    if (start == end)
        return maxTree[idx] = arr[start];
        
    return maxTree[idx] = max(maxInit(idx * 2, start, (start + end) / 2), maxInit(idx * 2 + 1, (start + end) / 2 + 1, end));
}

long long minSum(int idx, int start, int end, int left, int right)
{
    if (right < start || left > end)
        return (2e9);
    
    if (left <= start && end <= right)
        return minTree[idx];

    return min(minSum(idx * 2, start, (start + end) / 2, left, right), minSum(idx * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

long long maxSum(int idx, int start, int end, int left, int right)
{
    if (right < start || left > end)
        return (0);
    
    if (left <= start && end <= right)
        return maxTree[idx];

    return max(maxSum(idx * 2, start, (start + end) / 2, left, right), maxSum(idx * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    minInit(1, 0, N - 1);
    maxInit(1, 0, N - 1);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << minSum(1, 0, N - 1, a - 1, b - 1) << " " << maxSum(1, 0, N - 1, a - 1, b - 1) << "\n";
    }

    return (0);
}