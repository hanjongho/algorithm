#include <iostream>
#include <vector>
using namespace std;

struct position{
    int x1, x2, y1, y2;
};
int N, M, result = 2e9, island_cnt = 0;
int map[11][11], visited[11][11], connected[7];
int dirX[4] = {0,1,0,-1};
int dirY[4] = {1,0,-1,0};
vector<position> a;
int flag[]={0,};
position temp;

int pass(){
    for(int i=1; i<=island_cnt; i++)
        if(connected[i] != 1)
            return 0;
    return 1;
}

void powerset(int n, int depth, int count){
    
    if(count > island_cnt - 1)
        return;
    
    if( n == depth ){
        for(int i=1; i<=island_cnt; i++)
            connected[i] = i;
        
        for(int i=0;i<n;i++){
            if(flag[i]){
                
                int tmp1 = map[a[i].x1][a[i].y1];
                int tmp2 = map[a[i].x2][a[i].y2];
                
                if(connected[tmp1] > connected[tmp2]){
                    connected[tmp1] = min(connected[tmp1],connected[tmp2]);
                    if(tmp2 != 1){ // 1이 아니면
                        int tmp = connected[tmp2];
                        for(int i=0; i<island_cnt; i++){
                            if(connected[tmp]){ // 1이면
                                connected[tmp1] = min(connected[tmp1],connected[tmp]);
                                break;
                            }
                            else
                                tmp = connected[tmp];
                        }
                    }
                }
                else if(connected[tmp2] > connected[tmp1]){
                    connected[tmp2] = min(connected[tmp2],connected[tmp1]);
        
                    if(tmp1 != 1){ // 1이 아니면
                        int tmp = connected[tmp1];
                        for(int i=0; i<island_cnt; i++){
                            if(connected[tmp]){ // 1이면
                                connected[tmp2] = min(connected[tmp2],connected[tmp]);
                                break;
                            }
                            else
                                tmp = connected[tmp];
                        }
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(flag[i]){
                int tmp1 = map[a[i].x1][a[i].y1];
                int tmp2 = map[a[i].x2][a[i].y2];
                if(connected[tmp1] > connected[tmp2])
                    connected[tmp1] = min(connected[tmp1],connected[tmp2]);
                else if(connected[tmp2] > connected[tmp1])
                    connected[tmp2] = min(connected[tmp2],connected[tmp1]);
            }
        }
        
        if(pass()){ // 다 연결되어 있으면
            int cnt = 0;
            for(int i=0; i<n; i++){
                if(flag[i]){
                    if(a[i].x1 == a[i].x2)
                        for(int j=a[i].y1+1; j<a[i].y2; j++)
                            cnt++;
                    else if(a[i].y1 == a[i].y2)
                        for(int j=a[i].x1+1; j<a[i].x2; j++)
                            cnt++;
                }
            }
            result = min(result, cnt);
        }
        return;
    }
    flag[depth]=1;
    powerset(n,depth+1, count);
    flag[depth]=0;
    powerset(n,depth+1, count+1);
}

void dfs_(int x, int y, int number){
    map[x][y] = number;
    visited[x][y] = 1;
    for(int i=0; i<4; i++){
        int nx = x + dirX[i];
        int ny = y + dirY[i];
        if(nx < 1 || nx > N || ny < 1 || ny > M)
            continue;
        if(!visited[nx][ny] && map[nx][ny])
            dfs_(nx,ny,number);
    }
}

int main(){
    
    
    cin >> N >> M;
    for(int i=1; i<=N; ++i)
        for(int j=1; j<=M; ++j)
            cin >> map[i][j];
    
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
            if(map[i][j] && !visited[i][j])
                dfs_(i,j, ++island_cnt);
        
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=M; ++j){
            if(map[i][j]){
                temp.x1 = i;
                temp.y1 = j;
                if(!map[i][j+1] && !map[i][j+2] && j+2 < M){ // 오른쪽으로 다리놓을 수 있는지
                    for(int k=j+1; k<=M; k++){
                        if(map[i][k+1]){ // 섬 발견
                            temp.x2 = i;
                            temp.y2 = k+1;
                            a.push_back(temp);
                            break;
                        }
                    }
                }
                if(!map[i+1][j] && !map[i+2][j] && i+2 < N){ // 아래 다리놓을 수 있는지
                    for(int k=i+1; k<=N; k++){
                        if(map[k+1][j]){ // 섬 발견
                            temp.x2 = k+1;
                            temp.y2 = j;
                            a.push_back(temp);
                            break;
                        }
                    }
                }
            }
        }
    }
    
    powerset(a.size(), 0 , 0);
    
    if(result == 2e9)
        cout << -1;
    else
        cout << result;
    
    return 0;
}
