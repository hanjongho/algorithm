#include <iostream>
using namespace std;

int n, ans = -1;
int dp[501][501], tree[501][501];
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};


int dfs(int x, int y) {
    if(dp[x][y] != -1) // -1이 아니면 값이 들어 있는거니까 바로 메모이제이션으로 값 리턴
        return dp[x][y];
    
    dp[x][y] = 1; // -1이라면 처음 들어온거니까 1로 놓고 dp 값 저장
    
    for (int i = 0; i < 4; i++) {
        
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue;
        
        if (tree[x][y] < tree[nx][ny])
            dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
    }

    return dp[x][y];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> tree[i][j];
            dp[i][j] = -1;
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans = max(ans, dfs(i, j));

    cout << ans;
}
