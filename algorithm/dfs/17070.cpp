#include <iostream>
using namespace std;

int map[17][17];
int N, cnt = 0;

void dfs(int x, int y, int dir){ // 1 가로 2 대각선 3 세로
    
    if( x == N && y == N){
        cnt++;
        return;
    }
    
    if(dir == 1){
        if(!map[x][y+1] && y+1 <= N)
            dfs(x, y+1, 1);
        if(!map[x+1][y+1] && !map[x][y+1] && !map[x+1][y] && x+1 <= N && y+1 <= N)
            dfs(x+1, y+1, 2);
    }
    else if(dir == 2){
        if(!map[x][y+1] && y+1 <= N)
            dfs(x, y+1, 1);
        if(!map[x+1][y+1] && !map[x][y+1] && !map[x+1][y] && x+1 <= N && y+1 <= N)
            dfs(x+1, y+1, 2);
        if(!map[x+1][y] && x+1 <= N)
            dfs(x+1, y, 3);
    }
    else if(dir == 3){
        if(!map[x+1][y] && x+1 <= N)
            dfs(x+1, y, 3);
        if(!map[x+1][y+1] && !map[x][y+1] && !map[x+1][y] && x+1 <= N && y+1 <= N)
            dfs(x+1, y+1, 2);
    }
}


int main(){
    cin >> N;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            cin >> map[i][j];
    
    dfs(1,2,1); // 현 좌표 x, y , 방향 dir
    cout << cnt;
    
    return 0;
}
