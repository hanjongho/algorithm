#include <iostream>
using namespace std;
int N, M, X, x, y, z, cnt = 0, INF = 987654321, ans = -1;
int cost[1001][1001], cost_[1001][1001], result[1001][1001], visit[1001];

int findMin(int start){
    int tmp = INF, idx = -1;
    for(int i=1; i<=N; i++){
        if(!visit[i] && result[cnt][i] < tmp){ // 안가보고 작은값
            tmp = result[cnt][i];
            idx = i;
        }
    }
    visit[idx] = 1;
    return idx;
}

void dijkstra(int start){
    for(int i = 1; i<= N; i++){
        if(i != start)
            result[cnt][i] = INF;
        else
            result[cnt][start] = 0;
        visit[i] = 0;
    }
    for(int i=1; i<=N; i++){
        int t = findMin(start);
        for(int j=1; j<=N; j++){
            if(!cnt){
                if(cost[t][j] != 0 && result[cnt][t] + cost[t][j] < result[cnt][j])
                    result[cnt][j] = result[cnt][t] + cost[t][j];
            }
            else if(cnt){
                if(cost_[t][j] != 0 && result[cnt][t] + cost_[t][j] < result[cnt][j])
                    result[cnt][j] = result[cnt][t] + cost_[t][j];
            }
        }
    }
    cnt++;
}

int main(){
    cin >> N >> M >> X;
    for(int i=1; i<=M; i++){
        cin >> x >> y >> z;
        cost[x][y] = z;
        cost_[y][x] = z;
    }
    dijkstra(X); // result[0][1~N] 파티장에서 집 갈때
    dijkstra(X); // 뒤집은 배열로 각 노드에서 파티장 올때
    
    for(int i=1; i<=N; i++)
        if(result[0][i] + result[1][i] > ans)
            ans = result[0][i] + result[1][i];
    cout << ans;
    return 0;
}
