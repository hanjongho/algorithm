#include <iostream>
#include <math.h>
using namespace std;
 
int N, ans=0;
int queen[15];
 
bool isPossble(int x){
    for(int i=1; i<x; i++)
        if(queen[x] == queen[i] || x-i == abs(queen[x]-queen[i]))
            return false;
    return true;
}

void dfs(int x){
    if(x == N+1){
        ans++;
        return;
    }
    
    for(int i=1; i<=N; i++){
        queen[x] = i;
        if(isPossble(x))
            dfs(x+1);
        // queen[x] = 0; 새롭게 덮어쓰기에 안 써도 상관없음.
    }
}
int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    dfs(1);
    cout << ans;
    return 0;
}
 
