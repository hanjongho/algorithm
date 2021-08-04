#include <iostream>
#include <math.h>
using namespace std;
 
int N, ans = 0;
int queen[15];
 
int isPossble(int idx)
{
    for (int i = 1; i < idx; i++)
        if (queen[idx] == queen[i] || idx - i == abs(queen[idx] - queen[i]))
            return (0);
    return (1);
}

void dfs(int idx)
{
    if (idx == N + 1)
    {
        ans++;
        return ;
    }
    
    for (int i = 1; i <= N; i++)
    {
        queen[idx] = i;
        if (isPossble(idx))
            dfs(idx + 1);
        else
            queen[idx] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N;

    dfs(1);

    cout << ans << "\n";

    return (0);
}