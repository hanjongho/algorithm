#include <iostream>
#include <algorithm>
using namespace std;
char _[16];
int visited[16];


int L, C;

void dfs(int n, int cnt){
    if( n >= C || cnt == L){
        if(cnt == L){
            int mo = 0;
            for(int i=1; i<=C; i++)
                if(visited[i])
                    if(_[i] == 'a' || _[i] == 'e' || _[i] == 'i' || _[i] == 'o' || _[i] == 'u')
                        mo++;
            if( mo >= 1 && L - mo >= 2) {
                for(int i=1; i<=C; i++)
                    if(visited[i])
                        cout << _[i];
                cout << "\n";
            }
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
    
    cin >> L >> C;
    for(int i=1; i<=C; i++)
        cin >> _[i];
    
    sort(_+1, _+1+C);
    dfs(0, 0);
    
    return 0;
}
