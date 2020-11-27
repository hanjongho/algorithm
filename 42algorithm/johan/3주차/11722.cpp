#include <iostream>
using namespace std;

int main()
{
    int N, ANS = -1;
    int A[1001] = {0, }, DP[1001] = {0, };
    
    cin >> N;
    for (int i = N; i >= 1; i--)
        cin >> A[i];
    for (int i = 1; i <= N; i++)
    {
        DP[i] = 1;
        for (int j = 1; j < i; j++)
            if (A[i] > A[j])
                DP[i] = max(DP[j] + 1, DP[i]);
        ANS = max(ANS, DP[i]);
    }
    cout << ANS << "\n";
    return (0);
}