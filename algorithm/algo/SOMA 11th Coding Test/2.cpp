#include <iostream>
using namespace std;

int getParent(int parent[], int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = getParent(parent, parent[x]);
}

int unionParent(int parent[], int a, int b){
    a = getParent(parent, a);
    b = getParent(parent, b);
    
    if( a < b ){
        parent[b] = a;
        return a;
    }
    else{
        parent[a] = b;
        return b;
    }
}

int findParent(int parent[], int a, int b){
    a = getParent(parent, a);
    b = getParent(parent, b);
    if ( a == b ){
        return 1;
    }
    return 0;
}

int N, M, cntTeam = 0, ans = -1;
int abilityPositon[300001][2], parent[300001], saveTeamNumber[300001];

struct SquareSize{
    int x1 = 100001, y1 = 100001, x2 = 0, y2 = 0;
};
SquareSize team[300001];

int main(){
    cin >> N >> M;
    for(int i=1; i<=N; i++)
        cin >> abilityPositon[i][0] >> abilityPositon[i][1];
    
    for (int i=1; i<=N; i++)
        parent[i] = i;

    for(int i=1; i<=M; i++){
        int a, b;
        cin >> a >> b;
        unionParent(parent, a, b);
    }
    
    int  visited[300001];
    for(int i=1; i<=N; i++){
        if(!visited[parent[i]]){
            visited[parent[i]] = 1;
            saveTeamNumber[++cntTeam] = parent[i];
        }
    }
    
    for(int i=1; i<=N; i++){
        
        int myTeamNumber = getParent(parent, i);
        
        if(abilityPositon[i][0] < team[myTeamNumber].x1)
            team[myTeamNumber].x1 = abilityPositon[i][0];
        else if(abilityPositon[i][0] > team[myTeamNumber].x2)
            team[myTeamNumber].x2 = abilityPositon[i][0];
        
        if(abilityPositon[i][1] < team[myTeamNumber].y1)
            team[myTeamNumber].y1 = abilityPositon[i][1];
        else if(abilityPositon[i][1] > team[myTeamNumber].y2)
            team[myTeamNumber].y2 = abilityPositon[i][1];
        
    }
    for(int i=1; i<=cntTeam; i++){
        if(team[i].x1 != team[i].x2 && team[i].y1 != team[i].y2){
            if((team[i].x2 - team[i].x1)*2 + (team[i].y2 - team[i].y1)*2 > ans ){
                ans = (team[i].x2 - team[i].x1)*2 + (team[i].y2 - team[i].y1)*2;
            }
        }
    }
    
    cout << ans;
}
