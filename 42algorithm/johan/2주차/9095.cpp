#include <iostream>
using namespace std;

int main()
{
    int dp[12], number, temp;
    
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= 11; i++)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    cin >> number;
    for (int i = 0; i < number; i++)
    {
        cin >> temp;
        cout << dp[temp];
    }
    return (0);
}
