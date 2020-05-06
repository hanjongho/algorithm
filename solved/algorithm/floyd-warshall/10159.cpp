#include <iostream>
using namespace std;

int N, M;
int things[101][101];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M;

    while(M--){
        int small, big;
        cin >> small >> big;
        things[small][big] = 1;
    }
    
    for (int k = 1; k <= N; k++){
        for (int i = 1; i <= N; i++){
            for (int j = 1; j <= N; j++){
                if (i == j || i == k || j == k)
                    continue;
                if( things[i][k] && things[k][j] )
                    things[i][j] = 1;
            }
        }
    }
    
    
    for(int i=1; i<=N; i++){
        int tmp = 0;
        for(int j=1; j<=N; j++){
            if (i==j)
                continue;
            if (!things[i][j] && !things[j][i])
                tmp++;
        }
        cout << tmp <<"\n";
    }
}
