#include <iostream>
using namespace std;
 
int N, K, s = 0, sum = 0, ans = 0;
int arr[100001];
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
 
    for (int i = 0; i < K; i++)
        sum += arr[i];
    ans = sum;
    for (int i = 0; i < N - K; i++)
    {
        sum = sum - arr[i] + arr[i + K];
        ans = sum > ans ? sum : ans;
    }
 
    cout << ans << "\n";
    return (0);
}