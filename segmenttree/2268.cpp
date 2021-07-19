#include <iostream>
using namespace std;

long long arr[1000001], tree[4000004];

long long sum(int idx, int start, int end, int left, int right)
{
    if (right < start || left > end)
        return (0);

    if (start >= left && end <= right)
        return tree[idx];

    return sum(idx * 2, start, (start + end) / 2, left, right) + sum(idx * 2 + 1, (start + end) / 2 + 1, end, left, right);
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
        int a, b, c;
        cin >> a >> b >> c;
        
        if (a == 0)
        {
            if (b > c)
            {
                int temp = b;
                b = c;
                c = temp;
            }
            cout << sum(1, 0, N - 1, b - 1, c - 1) << "\n";
        }
        else
            update(1, 0, N - 1, b - 1, c);
    }

    return (0);
}