#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[100001], tree[400004];

int init(int idx, int start, int end)
{
    if (start == end)
        return tree[idx] = start;

    init(idx * 2, start, (start + end) / 2);
    init(idx * 2 + 1, (start + end) / 2 + 1, end);
    if (arr[tree[idx * 2]] < arr[tree[idx * 2 + 1]])
        return tree[idx] = tree[idx * 2];
    else
        return tree[idx] = tree[idx * 2 + 1];
}

int minIdx(int idx, int start, int end, int left, int right)
{
    if (start > right || end < left)
        return (-1);

    else if (left <= start && end <= right)
        return tree[idx];
    
    int leftQuery = minIdx(idx * 2, start, (start + end) / 2, left, right);
    int rightQuery = minIdx(idx * 2 + 1, (start + end) / 2 + 1, end, left, right);
    
    if (leftQuery == -1)
        return rightQuery;
    if (rightQuery == -1)
        return leftQuery;

    if (arr[leftQuery] < arr[rightQuery])
        return leftQuery;
    else
        return rightQuery;
}

long long getMaxArea(int N, int start, int end)
{
    int idx = minIdx(1, 0, N - 1, start, end);
    long long area = (end - start + 1) * (long long)arr[idx];
    
    if (start < idx)
        area = max(area, getMaxArea(N, start, idx - 1));

    if (idx < end)
        area = max(area, getMaxArea(N, idx + 1, end));

    return area;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    while (1)
    {
        int N;
        cin >> N;
        if (N == 0)
            break ;
        
        for (int i = 0; i < 400004; i++)
        {
            if (i < 100001)
                arr[i] = 0;
            tree[i] = 0;
        }

        for (int i = 0; i < N; i++)
            cin >> arr[i];
        
        init(1, 0, N - 1);
        
        cout << getMaxArea(N, 0, N - 1) << "\n";
    }

    return (0);
}
