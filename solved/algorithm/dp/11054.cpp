#include <iostream>
using namespace std;
int arr[1001], front_dp[1001], back_dp[1001], N, temp = 0;
int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    for(int i=1; i<=N; i++)
        cin >> arr[i];
    
    for(int i=1; i<=N; i++){
        front_dp[i]++;
        for(int j=1; j<i; j++)
            if(arr[j] < arr[i])
                front_dp[i] = max(front_dp[i], front_dp[j] + 1);
    }
    
    for(int i=N; i>=1; i--){
        back_dp[i]++;
        for(int j=N; j>i; j--)
            if(arr[j] < arr[i])
                back_dp[i] = max(back_dp[i], back_dp[j] + 1);
    }
    
    for(int i=1; i<=N; i++)
        temp = max(temp, front_dp[i] + back_dp[i]);
    cout << temp-1;
    return 0;
}
