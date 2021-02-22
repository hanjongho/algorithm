#include <iostream>
using namespace std;

int N;
int dp[16], t[16], p[16];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> t[i] >> p[i];

    for (int i = 1; i <= N + 1; i++)
        for (int j = t[i] + i; j <= N + 1; j++)
            dp[j] = max(dp[j], dp[i] + p[i]);

    cout << dp[N + 1];
    return (0);
}