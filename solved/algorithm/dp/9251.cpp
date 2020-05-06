#include <iostream>
#include <string.h>
using namespace std;

char a[1001], b[1001];
int LCS[1001][1001];

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> a >> b;
    
    for(int i=1; i<=strlen(a); i++){
        for(int j=1; j<=strlen(b); j++){
            if(a[i-1] == b[j-1])
                LCS[i][j] = LCS[i-1][j-1] + 1;
            else
                LCS[i][j] = max(LCS[i][j-1], LCS[i-1][j]);
        }
    }
    cout << LCS[strlen(a)][strlen(b)];
    
    return 0;
}
