#include <iostream>
#include <cstring>
#include <string>
#define MAX 17
#define INF 987654321
using namespace std;

int N, P, power = 1 << MAX;
int w[MAX][MAX], cache[MAX][1<<MAX];
string t;

int countBit(int n){
    if(!n)
        return 0;
    else return (n & 1) + countBit(n >> 1);
}

int getMinCost(int current, int state){
    if(countBit(state)-1 >= P) // 나를 제외하고 P개의 발전기가 켜져있으면
        return 0;

    int &result = cache[current][state];
    if(result != -1)
        return result;
    
    result = INF;
    for(int i=0; i<N; i++)
        // 꺼진 발전기를 찾으면
        if(!(state&(1<<i)))
            for(int j=0; j<N; j++)
                if((state | (1<<i)) & (1 << j))
                    result = min(result, w[current][i] + getMinCost(j, state | (1 << i)));
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> w[i][j];
    
    cin >> t;
    for(int i=0; i<t.size(); i++)
        if(t[i] == 'Y')
            power |= (1 << i); // 해당 비트 불을 켬
    
    cin >> P;
    if(!P)
        cout << 0;
    else{
        memset(cache, -1, sizeof(cache));
        int result = INF;
        for(int i=0; i<N; i++)
            if(t[i] == 'Y')
                result = min(result, getMinCost(i, power));
        
        if(result == INF)
            cout << -1;
        else
            cout << result;
    }
    
    return 0;
}
