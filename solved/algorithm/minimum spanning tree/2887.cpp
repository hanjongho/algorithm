#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct planet{
    int x,y,z,num;
};
struct edge{
    int weight,from,to;
};

vector<edge> ed;
planet pl[1000000];
int parent[100001];
int N, cnt = 0, ans = 0;

bool cmpx(planet a, planet b){
    return a.x < b.x;
}
bool cmpy(planet a, planet b){
    return a.y < b.y;
}
bool cmpz(planet a, planet b){
    return a.z < b.z;
}
bool cmp(edge a, edge b){
    return a.weight < b.weight;
}
int getParent(int x){
    if(parent[x] == x)
        return x;
    return parent[x] = getParent(parent[x]);
}
void merge(int x, int y){
    x = getParent(x);
    y = getParent(y);
    parent[x] = y;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    for(int i=0 ; i<N; i++){
        cin >> pl[i].x >> pl[i].y >> pl[i].z;
        pl[i].num = i;
        parent[i]=i;
    }

    sort(pl, pl+N, cmpx);
    for(int i=0 ; i<N-1; i++)
        ed.push_back({abs(pl[i].x - pl[i+1].x), pl[i].num, pl[i+1].num});
    
    sort(pl, pl+N, cmpy);
    for(int i=0 ; i<N-1; i++)
        ed.push_back({abs(pl[i].y - pl[i+1].y), pl[i].num, pl[i+1].num});
    
    sort(pl, pl+N, cmpz);
    for(int i=0 ; i<N-1; i++)
        ed.push_back({abs(pl[i].z - pl[i+1].z), pl[i].num, pl[i+1].num});
    
    sort(ed.begin(), ed.end(), cmp);
    
    for(int i = 0; i<ed.size(); i++){
        if(getParent(ed[i].from) != getParent(ed[i].to)){
            cnt++;
            ans += ed[i].weight;
            merge(ed[i].from, ed[i].to);
        }
        if(cnt == N-1)
            break;
    }
    cout << ans;
    return 0;
}
