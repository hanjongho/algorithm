#include <iostream>
using namespace std;
 
int A[500005], B[1000001], tree[500005 * 4];
 
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
 
long long query(int idx, int start, int end, int left, int right)
{
    if (right < start || left > end)
        return (0);

    if (left <= start && end <= right)
        return tree[idx];

    return query(idx * 2, start, (start + end) / 2, left, right) + query(idx * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;

        B[temp] = i;
    }

    long long result = 0;
    for (int i = 0; i < N; i++)
    {
        result += query(1, 0, N - 1, B[A[i]], N - 1);
        update(1, 0, N - 1, B[A[i]], 1);
    }

    cout << result << "\n";
    return 0;
}
