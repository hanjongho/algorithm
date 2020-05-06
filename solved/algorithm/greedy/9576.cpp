#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int test_case, N, M, a, b, cnt = 0;
int visited[1001];

struct books{
    int start, end;
};

bool func(books &p1, books &p2){
    if(p1.end < p2.end)
        return true;
    else if(p1.end == p2.end )
        return p1.start < p2.start;
    else
        return false;
}

int main(){
    vector<books> v;
    v.push_back({1,5});
    v.push_back({3,5});
    
    
    cin >> test_case;
    while(test_case--){
        
        vector<books> v;
        cnt = 0;
        
        cin >> N >> M;
        for(int i=1; i<=M; i++){
            cin >> a >> b;
            v.push_back({a,b});
        }
        
        sort(v.begin(), v.end(), func);
        
        for(int i=0; i<v.size(); i++){
            for(int j=v[i].start; j<=v[i].end; j++){
                if(!visited[j]){
                    visited[j] = 1;
                    cnt++;
                    break;
                }
            }
        }
        
        memset(visited, 0, sizeof(visited));
        v.clear();
        cout << cnt << endl;
    }
    
    
    return 0;
}
