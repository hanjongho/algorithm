#include <iostream>
#include <vector>
#define MAX 500001
using namespace std;

int n, m, l[MAX], r[MAX];
long long tree[MAX * 4], lazy[MAX * 4], salary[MAX], salary_[MAX];
vector<vector<int>> p;

void dfs(int now, int &cnt){ // L[i]는 내 번호, R[i]는 내 트리 기준 맨 마지막 인덱스
    l[now] = ++cnt;
    for (int next : p[now])
        dfs(next, cnt);
    r[now] = cnt;
}

void init(int node, int s, int e){
    if(s == e){
        tree[node] = salary_[s];
        return;
    }
    int m = (s + e) / 2;
    init(node * 2, s, m);
    init(node * 2 + 1, m + 1, e);
}

void update_lazy(int node, int s, int e){
    if(lazy[node]){
        tree[node] += lazy[node] * (e-s+1);
        if (s != e){ // 리프노드가 아니면
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int node, int s, int e, int i, int j, long long v){ // i~j 구간을 v로 바꿔라
    update_lazy(node, s, e);
    if (j < s || e < i) // s~e가 구간인데 벗어나면 return
        return;
    if (i <= s && e <= j){ // 구간안에 들어오면
        tree[node] += v;
        if(s != e){
            lazy[node * 2] += v;
            lazy[node * 2 + 1] += v;
        }
        return;
    }
    int m = (s + e) / 2;
    update(node * 2, s, m, i, j, v);
    update(node * 2 + 1, m + 1, e, i, j, v);
}

long long query(int node, int s, int e, int idx){
    update_lazy(node, s, e);
    if (idx < s || e < idx)
        return 0;
    if (s == e)
        return tree[node];
    
    int m = (s+e)/2;
    return query(node * 2, s, m, idx) + query(node * 2 + 1, m + 1, e, idx);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> salary[1];
    p.resize(n + 1);
    int x, y;
    
    for(int i=2; i<=n; i++){ // p[i]에는 아래 얘들이 들어있음
        cin >> salary[i] >> x;
        p[x].push_back(i);
    }
    int cnt = 0;
    dfs(1, cnt);
    
    for (int i=1; i<=n; i++)
        salary_[l[i]] = salary[i];
    init(1, 1, n);
    
    for (int i=0; i<m; i++){
        char c;
        cin >> c;
        if (c == 'p'){
            cin >> x >> y;
            update(1, 1, n, l[x] + 1, r[x], y);
        }
        else if(c == 'u'){
            cin >> x;
            cout << query(1, 1, n, l[x]) << "\n";
        }
    }
    cout <<"\n";
    for(int i=1; i<=3*n; i++)
        cout << tree[i] << " ";
    cout <<"\n";
    for(int i=1; i<=3*n; i++)
        cout << lazy[i] << " ";
    cout <<"\n";
}
