#include <iostream>
using namespace std;

/*
실패한 코드

316 * 316 = 99856 부터 넣어보는 방식이였으나, 
32 = 5^2 + 2^2 + 1^2 + 1^2 + 1^2 가 정답이 아닌
   = 2^4 + 2^4가 정답이였다. => 문제 잘못 이해

void dfs(int n, int count)
{
    if (n == 1)
    {
        cout << count + 1;
        return ;
    }
    for(int i = 316; i >= 1; i--)
        if (n > i * i)
        {
            dfs(n - i * i, count + 1);
            break ;
        }
}

int main()
{
    int N;
    cin >> N;
    dfs(N, 0);
    return (0);
}
*/

int main()
{
    int N, DP[100001];
    cin >> N;
    
    for (int i = 1; i <= N; i++)
    {
        DP[i] = i;
        for (int j = 1; j * j <= i; j++)
            DP[i] = min(DP[i], DP[i - j * j] + 1);
    }
    cout << DP[N];
}