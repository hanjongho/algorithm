#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, number;
int inDegree[10001], result[10001], t[10001];
queue<int> q;
vector<int> v[10001];

void topologySort(){
    for (int i = 1; i <= N; i++){
        if (inDegree[i] == 0){
            q.push(i);
            result[i] = t[i];
        }
    }
    while (!q.empty()){
        int now = q.front();
        q.pop();
        for (int i = 0; i < v[now].size(); i++){
            int next = v[now][i];
            result[next] = max(result[next], result[now] + t[next]);
            if (--inDegree[next] == 0)
                q.push(next);
        }
    }
}
int main(){
    cin >> N;
    for (int i = 1; i <= N; i++){
        cin >> t[i];
        cin >> number;
        while(number--){
            int x;
            cin >> x;
            v[i].push_back(x);
            inDegree[x]++;
        }
    }
    topologySort();
    int ans = 0;
    for (int i = 1; i <= N; i++)
        if(result[i] > ans)
            ans = result[i];
    printf("%d",ans);
    return 0;
}
