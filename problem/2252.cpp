#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int inDegree[32002], result[32002];
vector<int> a[32002];
queue<int> q;

void topologySort(){
    for (int i = 1; i <= N; i++) // 진입차수 0
        if (inDegree[i] == 0)
            q.push(i);
    
    for (int i = 1; i <= N; i++){ // 노드 갯수만큼 다 돌면 위상정렬 성공, 큐가 먼저 비어버리면 실패(cycle 발생)
        if (q.empty()){
            cout << "-1" << endl;
            return;
        }
        int x = q.front();
        result[i] = x;
        q.pop();
        for (int j = 0; j < a[x].size();j++){ // 간선 한개씩 제거
            int y = a[x][j];
            if (--inDegree[y] == 0)
                q.push(y);
        }
    }
    for (int i = 1; i <= N; i++)
        cout << result[i] << " ";
    cout << endl;
    
    return;
}

int main(){
    cin >> N >> M;
    for (int i = 1; i <= M; i++){
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        inDegree[y]++;
    }
    topologySort();
}
