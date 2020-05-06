#include <iostream>
#include <cstdlib>
using namespace std;

int N, result = 0;
int map[15][15];

void dfs(int x){
    if(x == N){
        result++;
        return;
    }
    
    
    for(int i=1; i<=N; i++){ // i가 y값
        
        map[x][i] = 1;
        
        int flag = 1;
        
        for(int j=1; j<x; j++){ // in the same column
            if(map[x][i] == map[j][i]){
                flag = 0;
                break;
            }
        }
        
        for(int k=1; k<x; k++){ // in the same cross
            for(int j=1; j<=N; j++){
                if(map[k][j] && abs(k-x) == abs(j-i)){
                    flag = 0;
                    break;
                }
            }
        }
        if(flag)
            dfs(x+1);
        else
            map[x][i] = 0;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    
    for(int i=1; i<=N; i++){
        map[1][i] = 1;
        dfs(2);
        map[1][i] = 0;
    }
    cout << result;
    
    return 0;
}
