#include <iostream>
using namespace std;
#define INF 987654321

int n, m, a, b, result = 0;
int relation[501][501], front[501], back[501];

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            relation[i][j] = INF;
        
    while(m--){
        cin >> a >> b;
        relation[a][b] = 1;
    }

    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (i == j || i == k || j == k)
                    continue;
                
                relation[i][j] = min(relation[i][j], relation[i][k] + relation[k][j]);
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++){
            if (i == j)
                continue;
            if (relation[i][j] != INF){
                front[i]++;
                back[j]++;
            }
        }
    }

    for (int i = 1; i <= n; i++)
        if (front[i] + back[i] == n - 1)
            result++;

    cout << result;

    return 0;
}
