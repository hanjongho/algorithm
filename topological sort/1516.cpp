#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, number;
int inDegree[501], dist[501], t[501];
queue<int> q;
vector<int> v[501];

void topologySort(){
    for (int i = 1; i <= N; i++){
        if (inDegree[i] == 0){
            q.push(i);
            dist[i] = t[i];
        }
    }
    while (!q.empty()){
        int now = q.front();
        q.pop();
        for (int i = 0; i < v[now].size(); i++){
            int next = v[now][i];
            dist[next] = max(dist[next], dist[now] + t[next]);
            if (--inDegree[next] == 0)
                q.push(next);
        }
    }
}
int main(){
    cin >> N;
    for (int i = 1; i <= N; i++){
        cin >> number;
        t[i] = number;
        while (scanf("%d",&number) && number != -1){
            v[number].push_back(i);
            inDegree[i]++;
        }
    }
    topologySort();
    for (int i = 1; i <= N; i++)
        cout << dist[i] << "\n";
    return 0;
}
