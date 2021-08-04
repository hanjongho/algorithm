#include <iostream>
using namespace std;

long long arr[100001], tree[400004]; 

long long init(int idx, int start, int end)
{
    if (start == end)
        return tree[idx] = arr[start];
    
    return tree[idx] = init(idx * 2, start, (start + end) / 2) * init(idx * 2 + 1, (start + end) / 2 + 1, end);
}

long long multiply(int idx, int start, int end, int left, int right)
{
    if (start > right || end < left)
        return (1);

    if (start >= left && end <= right)
        return tree[idx];

    return multiply(idx * 2, start, (start + end) / 2, left, right) * multiply(2 * idx + 1, (start + end) / 2 + 1, end, left, right);
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
    tree[idx] = tree[idx * 2] * tree[idx * 2 + 1];
}

int main() 
{
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int N, K;
    while (cin >> N >> K)
    {
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
            if (arr[i] > 0)
                arr[i] = 1;
            else if (arr[i] < 0)
                arr[i] = -1;
        }

        init(1, 0, N - 1);

        for (int i = 0; i < K; i++)
        {
            char c;
            int a, b;
            cin >> c >> a >> b;
            if (c == 'C')
            {
                if (b > 0)
                    b = 1;
                else if (b < 0)
                    b = -1;

                update(1, 0, N - 1, a - 1, b);
            }
            else if (c == 'P')
            {
                long long result = multiply(1, 0, N - 1, a - 1, b - 1);
                if (result == 0)
                    cout << "0";
                else if (result < 0)
                    cout << "-";
                else if (result > 0)
                    cout << "+";
            }
        }
        cout << "\n";
    }
    return (0);
}