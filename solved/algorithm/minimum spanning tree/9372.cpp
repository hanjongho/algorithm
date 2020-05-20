#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int N, M;
        cin >> N >> M;
        for (int i= 0, a, b; i < M; i++)
            cin >> a >> b;
        cout << N-1 << "\n";
    }
    return 0;
}
