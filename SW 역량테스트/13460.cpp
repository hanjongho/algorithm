#include <iostream>
#include <queue>
using namespace std;

int N, M;
char map[11][11];

struct point {
    int rx, ry, bx, by;
};

queue <point> q;

int cnt, ans;
int rx, ry, bx, by;
int nrx, nry, nbx, nby;
int orx, ory, obx, oby;
int direction[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int visit[11][11][11][11];

void BFS() {
    while (!q.empty()) {
        int q_size = q.size();
        
        for (int i = 0; i < q_size; i++)
        {
            orx = q.front().rx;
            ory = q.front().ry;
            obx = q.front().bx;
            oby = q.front().by;
            q.pop();
            
            
            if (map[orx][ory] == 'O' && map[obx][oby] != 'O') { // 빨간공만 들어갔을 경우 성공 나머지는 다 실패한 경우.
                ans = cnt;
                return;
            }
            
            for (int j = 0; j < 4; j++)
            {
                rx = orx;
                ry = ory;
                bx = obx;
                by = oby;
                
                while (1) {
                    nrx = rx + direction[j][0];
                    nry = ry + direction[j][1];
                    
                    if (map[nrx][nry] == '#' || map[rx][ry] == 'O')
                        break;
                    
                    rx = nrx;
                    ry = nry;
                }
                
                while(1){
                    nbx = bx + direction[j][0];
                    nby = by + direction[j][1];
                    
                    if (map[nbx][nby] == '#' || map[bx][by] == 'O')
                        break;
                    
                    bx = nbx;
                    by = nby;
                }
                
                 if (rx == bx && ry == by) {
                     
                     if (map[bx][by] == 'O')
                         continue;
                     
                     if (abs(orx - rx) + abs(ory - ry) > abs(obx - rx) + abs(oby - ry)) {
                         rx -= direction[j][0];
                         ry -= direction[j][1];
                     }
                     
                     else {
                         bx -= direction[j][0];
                         by -= direction[j][1];
                     }
                 }
                
                if (visit[rx][ry][bx][by])
                    continue;
                
                visit[rx][ry][bx][by] = 1;
                q.push({ rx,ry,bx,by });
                
            }
        }
        
        if (cnt >= 10) {
            ans = -1;
            return;
        }
        cnt++;
    }
    
    ans = -1;
    return;
    
}

int main(){
    
    cin >> N >> M;
    
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> map[i][j];
            
            if (map[i][j] == 'R') {
                rx = i;
                ry = j;
                map[i][j] = '.';
            }
            else if (map[i][j] == 'B') {
                bx = i;
                by = j;
                map[i][j] = '.';
            }
        }
    }
    
    visit[rx][ry][bx][by] = 1;
    q.push({ rx,ry,bx,by });
    
    BFS();
    
    cout << ans << "\n";
    
    return 0;
}
