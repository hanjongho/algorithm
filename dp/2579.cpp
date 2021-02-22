#include <iostream>
using namespace std;

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int main()
{
    int number;
    int data[301], dp[301][2];

    cin >> number;
    for (int i = 1; i <= number; i++)
		cin >> data[i];
    for (int i = 1; i <= number; i++)
    {
        if (i < 3)
        {
            dp[i][0] = data[i];
            dp[i][1] = dp[i - 1][0] + data[i];
        }
        else
        {
            dp[i][0] = max(dp[i - 2][0], dp[i - 2][1]) + data[i];
            dp[i][1] = dp[i - 1][0] + data[i];
        }
    }
    cout << max(dp[number][0], dp[number][1]);
    return (0);
}