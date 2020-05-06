#include <iostream>
#include <vector>
using namespace std;

int map[9][9];
vector<pair<int, int>> v;

int rowCheck(int x, int y, int n){
    for(int i=0;i<9;i++){
        if(n == map[x][i]) return 0;
        
    }
    return 1;
}

int columnCheck(int x, int y, int n){
    for(int i=0;i<9;i++){
        if(n == map[i][y]) return 0;
    }
    return 1;
}

int SquareCheck(int x, int y, int n){
    int sx = (x/3)*3;
    int sy = (y/3)*3;
    for(int i=sx; i<sx+3; i++)
        for(int j=sy; j<sy+3; j++)
            if(n == map[i][j])
                return 0;
    return 1;
}

int dfs(int x, int y, int n){
    if(n == v.size()+1) {
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++)
                cout<< map[i][j] <<" ";
            cout<<"\n";
        }
        exit(0);
    }
    
    for(int i=1;i<=9;i++){
        if(rowCheck(x, y, i) && columnCheck(x, y, i) && SquareCheck(x, y, i)){
            map[x][y]=i;
            if(!dfs(v[n].first, v[n].second, n+1))
                map[x][y]=0;
            else
                return 1;
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin >> map[i][j];
            if(map[i][j]==0)
                v.push_back(make_pair(i,j));
        }
    }
    
    dfs(v[0].first, v[0].second, 1);
    
    return 0;
}
