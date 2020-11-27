#include <iostream>
using namespace std;

int main()
{
    int N, ANS = -1;
    int A[1001] = {0, }, DP[1001] = {0, };
    
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    DP[1] = A[1];
    for (int i = 1; i <= N; i++)
    {
        DP[i] = A[i];
        for (int j = 1; j < i; j++)
            if (A[i] > A[j])
                DP[i] = max(A[i] + DP[j], DP[i]);
        ANS = max(ANS, DP[i]);
    }
    cout << ANS << "\n";
    return (0);
}