#include <iostream>
#include <queue>
 
using namespace std;
 
int N, M, result = 0;
int map[53][53], visit[53][53], visit2[53][53];
 
int dir_x[4] = {-1,1,0,0};
int dir_y[4] = {0,0,1,-1};
 
void copy(){
    for (int i = 0; i < 53; i++)
        for (int j = 0; j < 53; j++)
            visit2[i][j] = visit[i][j];
}

int main()
{
    cin >> N >> M;
 
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            scanf("%1d",&map[i][j]);
   
 
    for (int wall = 9; wall >= 1; wall--){
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
                if (map[i][j] == wall)
                    visit[i][j] = 1;
 
        for (int i = 1; i <= N; i++){
            for (int j = 1; j <= M; j++){
                if (!visit[i][j]){
                    copy();
                    bool flag = true;
                    queue <pair<int,int>> q1, q2;
                    q1.push({i,j});
                    q2.push({i,j});
                    visit2[i][j] = 1;
 
                    while (!q1.empty()){
                        int px = q1.front().first;
                        int py = q1.front().second;
                        q1.pop();

                        if (map[px][py] == 0){
                            flag = false;
                            break;
                        }

                        for (int k = 0; k < 4; k++){
                            int nx = px + dir_x[k];
                            int ny = py + dir_y[k];
                            if (!visit2[nx][ny]){
                                visit2[nx][ny] = 1;
                                q1.push(make_pair(nx, ny));
                                q2.push(make_pair(nx, ny));
                            }
                        }
                    }
 
                    if (flag){
                        while (!q2.empty()){
                            int px = q2.front().first;
                            int py = q2.front().second;
                            q2.pop();
                            result += wall - map[px][py];
                            visit[px][py] = 1;
                        }
                    }
                }
            }
        }
    }
 
    cout << result;
 
    return 0;
}
