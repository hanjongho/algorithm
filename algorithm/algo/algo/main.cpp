#include <iostream>
using namespace std;

int N;
int skillTime[100001][2], ableAttackCnt[100001];

int main(){
    cin >> N;
    for(int i=1; i<=N; i++)
        cin >> skillTime[i][0] >> skillTime[i][1];
    
    for(int i=1; i<=N; i++){     // [i][0] = s1, [i][1] = e1
        for(int j=1; j<=N; j++){ // [j][0] = s2, [j][1] = e2
            
            if(i == j)
                continue;
            
            if(skillTime[j][0] < skillTime[i][0] && skillTime[i][0] < skillTime[j][1]){
                ableAttackCnt[i]++;
            }
        }
    }
    for(int i=1; i<=N; i++)
        cout << ableAttackCnt[i] << "\n";
    
    return 0;
}
