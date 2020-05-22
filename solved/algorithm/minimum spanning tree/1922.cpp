/*
 
 1. 비용으로 정렬을 한다.
 2. 낮은순으로 돌리면서 union-find로 싸이클 여부 확인한다.
 
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, a, b, c, ans = 0;
int parent[10001];
pair<pair<int,int>, int> v[100001];

bool cmp(pair<pair<int,int>, int> v1, pair<pair<int,int>, int> v2){
    return v1.second < v2.second;
}

int getParent(int x){
    if(parent[x] == x)
        return x;
    return getParent(parent[x]);
}

int cycle_check(int a, int b){
    int x = getParent(a);
    int y = getParent(b);
    
    if (x == y)
        return 0;
    return 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M;
    for(int i=1; i<=N; i++)
        parent[i] = i;
    
    for(int i=0; i<M; i++){
        cin >> a >> b >> c;
        v[i].first.first = a;
        v[i].first.second = b;
        v[i].second = c;
    }
    sort(v, v+M, cmp);
    
    for(int i=0; i<M; i++){
        if(cycle_check(v[i].first.first, v[i].first.second)){
            ans += v[i].second;
            
            a = getParent(v[i].first.first);
            b = getParent(v[i].first.second);
            
            if( a < b )
                parent[b] = a;
            else
                parent[a] = b;
        }
    }
    cout << ans;
    
    return 0;
}
