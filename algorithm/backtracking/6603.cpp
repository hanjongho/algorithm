#include <iostream>
#include <string.h>
using namespace std;

int k;
int lotto[50], visited[50];

void dfs(int n, int cnt){
    if( n >= k || cnt == 6){
        if( cnt == 6){
            for(int i=1; i<=k; i++){
                if(visited[i])
                    cout << lotto[i] << " ";
            }
            cout << "\n";
        }
        return;
    }
    visited[n+1] = 1;
    dfs(n+1, cnt+1);
    visited[n+1] = 0;
    dfs(n+1, cnt);

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    while(1){
        memset(lotto, 0 ,sizeof(lotto));
        memset(visited, 0 ,sizeof(visited));
        cin >> k;
        if(!k)
            break;
        for(int i=1; i<=k; i++)
            cin >> lotto[i];
        
        dfs(0, 0);
        cout << "\n";
    }
    
    
    return 0;
}
