#include <iostream>
using namespace std;

int arr[100001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, S, sum, low = 0, high = 0, cnt = 0;
	
    cin >> N >> S;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sum = arr[0];
    while (low <= high && high < N)
    {
        if (sum == M)
            ans++;
        if (sum >= M)
            sum -= arr[low++];
        if (sum < M)
            sum += arr[++high];
    }
    cout << cnt << "\n";
    return (0);
}