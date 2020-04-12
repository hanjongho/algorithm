#include <iostream>
#define MAX 987654321
using namespace std;

int n, m, i, j, v;
int map[101][101];

int main(){
    cin >> n >> m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            map[i][j] = MAX;
    
    for(int i=1; i<=n; i++)
        map[i][i] = 0;
    
    while(m--){
        cin >> i >> j >> v;
        if(!map[i][j]) // 0이면
            map[i][j] = v;
        else
            map[i][j] = min(map[i][j], v);
    }
    
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                map[i][j] = min(map[i][j],map[i][k] + map[k][j]);
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(map[i][j] == MAX)
                map[i][j] = 0;
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}
