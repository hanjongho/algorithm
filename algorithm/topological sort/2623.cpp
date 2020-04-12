#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, t;
int inDegree[1001], result[1001];
vector<int> a[1001], ans;
queue<int> q;

void topologySort(){
    for (int i = 1; i <= N; i++)
        if (inDegree[i] == 0)
            q.push(i);
    
    while(!q.empty()){
        int now = q.front();
        q.pop();
        ans.push_back(now);
        for (int i = 0; i < a[now].size(); i++){
            int next = a[now][i];
            if (--inDegree[next] == 0)
                q.push(next);
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin >> t;
        for(int j=0; j<t; j++)
            cin >> result[j];
        for(int j=0; j<t-1; j++){
            a[result[j]].push_back(result[j+1]);
            inDegree[result[j+1]]++;
        }
    }
    
    topologySort();
    if(ans.size() != N)
        cout << "0";
    else
        for(int a : ans)
            cout << a << "\n";
    return 0;
}
