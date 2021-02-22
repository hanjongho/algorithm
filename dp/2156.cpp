#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, max_ = -1;
    int arr[10001], dp[10001];
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    if (n == 1)
        cout << arr[1];
    else if (n == 2)
        cout << arr[1] + arr[2];
    else {
        dp[1] = arr[1];
        dp[2] = arr[1] + arr[2];
        for(int i = 3; i <= n; i++)
            dp[i] = max(max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]), dp[i - 1]);
        cout << dp[n];
    }
    return (0);
}