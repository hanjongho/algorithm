#include <iostream>
using namespace std;

int N, tmp;
int arr[1001], dp[1001];

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    
    dp[N] = arr[N];

    for (int i = N - 1; i > 0; i--) {
        tmp = 0;
        for (int j = i; j <= N; j++) {
            if (dp[j] > tmp && arr[i] < arr[j])
                tmp = dp[j];
        }
        dp[i] = tmp + arr[i];
    }

    for (int i = 1; i <= N; i++)
        if (dp[i] > tmp)
            tmp = dp[i];
    printf("%d ", tmp);


    return 0;
}
