#include <iostream>
#include <algorithm>
using namespace std;
int n;
int A[4001], B[4001], C[4001], D[4001];
int AB[16000001], CD[16000001];
long long cnt = 0;
int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            AB[i * n + j] = A[i] + B[j];
        
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            CD[i * n + j] = C[i] + D[j];

    sort(CD, CD + n * n);
    
    for (int i = 0; i < n * n; i++)
        cnt += upper_bound(CD, CD + n * n, -AB[i]) - lower_bound(CD, CD + n * n, -AB[i]);
        
    cout << cnt;
    
    return 0;
}
