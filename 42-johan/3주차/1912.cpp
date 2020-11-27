#include <iostream>
using namespace std;

int main()
{
    int n, ans = -1001;
    int a[100001] ={0,}, dp[100001] = {0,}; 
    
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        dp[i] = a[i];
        int sum = a[i];
        int j = i;
        while (sum + a[++j] > 0 && j <= n)
        {
            sum += a[j];
            dp[i] = max(dp[i], sum);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return (0);
}