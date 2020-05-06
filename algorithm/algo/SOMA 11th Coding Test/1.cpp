#include <iostream>
using namespace std;

int N, ans = -1;
int sugarContent[100001];
int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    for(int i=1; i<=N; i++)
        cin >> sugarContent[i];
    
    for(int i=1; i<=N; i++){
        sugarContent[i] = max(sugarContent[i-1] + sugarContent[i], sugarContent[i]);
        ans = max(ans, sugarContent[i]);
    }
    cout << ans;
}
