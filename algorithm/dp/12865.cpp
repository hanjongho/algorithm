#include <iostream>
using namespace std;

int N, K;
int w[101], v[101], dp[101][100001];
 
int main(){
    cin >> N >> K;
 
    for (int i = 1; i <= N; i++)
        cin >> w[i] >> v[i];
 
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= K; j++){
            dp[i][j] = dp[i-1][j]; // i번째 물건 못넣는게 default
            if (j-w[i] >= 0) // 물건을 넣을 수 있는 선택이 가능하면
                // i번째 물건을 넣은거랑 안 넣은 것중 더 큰 것으로 선택
                dp[i][j] = max(dp[i][j] , dp[i - 1][j - w[i]] + v[i]);
        }
    }
    cout << dp[N][K];
    return 0;
}
