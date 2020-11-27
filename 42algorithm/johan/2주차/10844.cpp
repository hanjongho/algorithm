#include <iostream>
using namespace std;

int main()
{
    int N;
    long long dp[101][10] = { 0, }, sum;
    for (int i = 1; i <= 9; i++)
        dp[1][i] = 1; // 길이가 1일 때, 마지막 수가 i일 경우의 계단 수
    
    cin >> N;
    for (int i = 2; i <= N;i++)
        for (int j = 0; j <= 9; j++)
        {
            if (j == 0)
                dp[i][j] = dp[i - 1][j + 1] % 1000000000;
            else if(j == 9)
                dp[i][j] = dp[i - 1][j - 1] % 1000000000;
            else
                dp[i][j] = (dp[i - 1][j + 1] + dp[i - 1][j - 1]) % 1000000000;
        }

    for (int i = 0; i <= 9; i++)
        sum += dp[N][i];

    sum %= 1000000000;
    cout << sum;
    return (0);
}
