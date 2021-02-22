#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, ans = -1001;
    int a[100001], dp[100001];
    
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