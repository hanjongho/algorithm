#include <iostream>
using namespace std;

int N;
int dp[16], t[16], p[16];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    for (int i=1; i<=N; i++)
        cin >> t[i] >> p[i];

    for (int i=1; i<=N+1; i++){
        if (t[i]+i <= N+1) // 상담을 더 진행해도 가능하면
            for (int j=t[i]+i; j<=N+1; j++)
                dp[j] = max(dp[j], dp[i] + p[i]);
    }
    cout << dp[N+1]; // 금액은 이후에 받기때문에
    return 0;
}
