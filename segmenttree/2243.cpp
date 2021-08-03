#include <iostream>
using namespace std;

long long tree[4000004];
 
void update(int idx, int start, int end, int findIdx, int changeValue)
{
    if (findIdx < start || findIdx > end) 
        return ;

    if (start == end)
    {
        tree[idx] += changeValue;
        return ;
    }

    update(idx * 2, start, (start + end) / 2, findIdx, changeValue);
    update(idx * 2 + 1, (start + end) / 2 + 1, end, findIdx, changeValue);
    tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}
 
long long sum(int idx, int start, int end, int rank) 
{
    if (start == end)
        return start;

    if (rank <= tree[idx * 2])
        return sum(idx * 2, start, (start + end) / 2, rank);
    else
        return sum(idx * 2 + 1, (start + end) / 2 + 1, end, rank - tree[idx * 2]);
}
 
int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        int A;
        cin >> A;
        if (A == 1)
        {
            int B;
            cin >> B;
            long long ans = sum(1, 1, 1000000, B);
            update(1, 1, 1000000, ans, -1);
            cout << ans << "\n";
        }
        else
        {
            int B, C;
            cin >> B >> C;
            update(1, 1, 1000000, B, C);
        }
    }
}
