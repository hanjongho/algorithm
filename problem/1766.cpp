#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M, inDegree[32001];
vector<int> vt[32001];
priority_queue<int> pq;

void topologySort(){
    for (int i = 1; i <= N; i++) {
        if (inDegree[i] == 0)
            pq.push(-i);
    }
    while (pq.size()) {
        int x = -pq.top();
        pq.pop();
        cout << x << " ";
        for (int i = 0; i < vt[x].size(); i++){
            int y = vt[x][i];
            inDegree[y]--;
            if (inDegree[y] == 0)
                pq.push(-y);
        }
    }
}
int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        vt[x].push_back(y);
        inDegree[y]++;
    }
    topologySort();
    return 0;
}
