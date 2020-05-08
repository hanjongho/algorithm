#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int TC;
    cin >> TC;
    while(TC--){
        int N, M, W, a, b, c;
        vector<pair<int, int>> v[501];
        bool cycle = false;
        int dist[501];
        
        cin >> N >> M >> W;
        for(int i=0; i<M+W; i++){
            cin >> a >> b >> c;
            if(i >= M){
                v[a].push_back(make_pair(b, -c));
            }
            else{
                v[a].push_back(make_pair(b, c));
                v[b].push_back(make_pair(a, c));
            }
        }
        for (int i = 1; i <= N; i++)
               dist[i] = INF;
        
        dist[1] = 0;
        for(int i = 1; i <= N; i++) { // 시작점
            for(int j = 1; j <= N; j++) { // 기준점
                for(int k = 0; k < v[j].size(); k++) { // 기준점 정보 다 털기
                    int dest = v[j][k].first;
                    int cost = v[j][k].second;
                    
                    if (dist[dest] > cost + dist[j]) {
                        dist[dest] = cost + dist[j];
                        if (i == N)
                            cycle = true;
                    }
                }
            }
        }
        
        if(cycle)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
