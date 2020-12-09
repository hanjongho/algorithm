#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct meeting{
    int start, end;
};

bool cmp(meeting mt1, meeting mt2){ // 무적권 빨리 끝나는 것 앞으로 / 같이 끝난다면 시작이 빠른 걸로.
    if(mt1.end == mt2.end)
        return mt1.start < mt2.start;
    return mt1.end < mt2.end;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
	int N, cnt = 0, tmp = 0;
    cin >> N;
    vector<meeting> t(N);
    
    for(int i=0; i<N; i++)
        cin >> t[i].start >> t[i].end;
    sort(t.begin(), t.end(), cmp);
    for(int i = 0; i < N; i++){
        if( tmp <= t[i].start){
            tmp = t[i].end;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
