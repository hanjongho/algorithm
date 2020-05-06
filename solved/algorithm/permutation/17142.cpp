#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

char map[51][51], map_c[51][51];
int N, M, result = 2e9;
int dirX[4] = {-1,1,0,0};
int dirY[4] = {0,0,1,-1};
bool flag[11];
vector <pair<int,int>> virus;

void copy(){
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            map[i][j] = map_c[i][j];
}
void print(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}
int check(){
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            if(map[i][j] == '0')
                return 0;
    return 1;
}
void permutation(int size, int idx){
    if(size > virus.size())
        return;
    if(idx == M){
        queue <pair<pair<int,int>,int>> q;
        for(int i=0; i<virus.size(); i++){
            if(flag[i]){
                q.push({{virus.at(i).first, virus.at(i).second},1});
                map[virus.at(i).first][virus.at(i).second] = '@';
            }
            else
                map[virus.at(i).first][virus.at(i).second] = '*';
        }
        int total = 0;
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int second = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nx = x + dirX[i];
                int ny = y + dirY[i];
               
                if(nx < 1 || nx > N || ny < 1 || ny > N)
                    continue;
                
                if(map[nx][ny] == '0'){ // 빈칸
                    map[nx][ny] = second +'0';
                    q.push({{nx,ny},second+1});
                    if(second > total)
                        total = second;
                }
                
                if(map[nx][ny] == '*' && !check()){
                    map[nx][ny] = second +'0';
                    q.push({{nx,ny},second+1});
                    if(second > total)
                        total = second;
                }
            }
        }
        if(check())
            if(total < result)
                result = total;
            
        copy();
        return;
    }
    
    flag[size] = 1;
    permutation(size+1, idx+1);
    flag[size] = 0;
    permutation(size+1, idx);
}

int main(){
    cin >> N >> M;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++){
            cin >> map[i][j];
            if(map[i][j] == '2') //
                virus.push_back({i,j});
            if(map[i][j] == '1')
                map[i][j] = '-';
            map_c[i][j] = map[i][j];
        }
    flag[0] = 1;
    permutation(1, 1);
    flag[0] = 0;
    permutation(1, 0);
    
    if(result == 2e9)
        cout << "-1";
    else
        cout << result;
    return 0;
}
