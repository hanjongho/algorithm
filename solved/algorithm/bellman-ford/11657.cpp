#include <iostream>
#include <vector>
#define INF 9876543
using namespace std;

int N, M, A, B, C;
vector<pair<int, int>> v[501];
bool cycle = false;
long long dist[501] = {INF,};

void bellman_ford(){
    for(int i = 1; i <= N; i++) { // 시작점
         for(int j = 1; j <= N; j++) { // 기준점
             for(int k = 0; k < v[j].size(); k++) { // 기준점 정보 다 털기
                 int dest = v[j][k].first;
                 int cost = v[j][k].second;
                 
                 if (dist[j] != INF && dist[dest] > cost + dist[j]) {
                     dist[dest] = cost + dist[j];
                     if (i == N)
                         cycle = true;
                 }
             }
         }
     }
}

int main(){
   
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    while(M--){
        cin >> A >> B >> C;
        v[A].push_back(make_pair(B, C));
    }

    for (int i = 1; i <= N; i++)
        dist[i] = INF;
    
    dist[1] = 0;

    bellman_ford();

    if(cycle)
        cout << -1 << "\n";
    else{
        for (int i = 2; i <= N; i++){
            if (dist[i] == INF)
                cout << -1 << "\n";
            else
                cout << dist[i] << "\n";
        }
    }
    return 0;
}
