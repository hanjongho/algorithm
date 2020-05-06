#include <iostream>
#include <algorithm>
using namespace std;
 

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, sum = 0, start, end;
    pair<int,int> vList[1000001];

    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> start >> end;
        vList[i].first = start;
        vList[i].second = end;
    }
    
    sort(vList + 1, vList + N + 1);
    
    start = -1000000001, end = -1000000001;
    
    for(int i = 1; i <= N; i++){
        if(end < vList[i].first){
            sum += end - start;
            start = vList[i].first;
            end = vList[i].second;
        }
        else end = max(end, vList[i].second);
    }
    sum += end - start;
    cout << sum;
    return 0;
}
