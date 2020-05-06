#include <iostream>
using namespace std;

int n, m, s, a, b;
int accidents[401][401];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;

    while(m--){
        cin >> a >> b;
        accidents[a][b] = 1;
    }
    
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (i == j || i == k || j == k)
                    continue;
                if( accidents[i][k] && accidents[k][j] )
                    accidents[i][j] = 1;
            }
        }
    }
    
    cin >> s;
    while(s--){
        cin >> a >> b;
        if(accidents[a][b] == 1)
            cout << "-1\n";
        else if(accidents[a][b] == 0 && accidents[b][a] == 1)
            cout << "1\n";
        else if(accidents[a][b] == 0 && accidents[b][a] == 0)
            cout << "0\n";
    }
}
