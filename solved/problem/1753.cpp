#include <iostream>
using namespace std;

int V, E, K, u, v, w, INF = 987654321;
int visited[20001], dis[20001], map[20001][20001];

int findSmallest(){
    int tmp = INF, idx = 0;
    for(int i=1; i<=V; i++){
        if(!visited[i] && dis[i] < tmp){
            tmp = dis[i];
            idx = i;
        }
    }
    if(tmp != INF)
        return idx;
    return 0;
}

int checked(){
    for(int i=1; i<=V; i++)
        if(!visited[i])
            return 0;
    return 1;
}

int main(){
    cin >> V >> E >> K;
    
    for(int i=1; i<=V; i++)
        for(int j=1; j<=V; j++)
            map[i][j] = INF;
    
    for(int i=1; i<=E; i++){
        cin >> u >> v >> w;
        map[u][v] = w;
    }
    
    for(int i=1; i<=V; i++)
        dis[i] = INF;
    dis[K] = 0;
    while(!checked()){ // 아직 갈 곳이 남아 있으면
        visited[K] = 1;
        for(int i=1; i<=V; i++){
            if(dis[i] > dis[K] + map[K][i]){
                dis[i] = dis[K] + map[K][i];
            }
        }
        K = findSmallest();
        if(!K)
            break;
    }
    
    for(int i=1; i<=V; i++){
        if(dis[i] != INF)
            printf("%d\n",dis[i]);
        else
            printf("INF\n");
    }
    return 0;
}
