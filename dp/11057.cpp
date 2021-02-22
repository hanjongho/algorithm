#include <iostream>
using namespace std;

int data_[10], dp[10];
int N, sum;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (int i = 0; i < 10; i++)
        data_[i] = 1;
    cin >> N;

    for (int i = 0; i < N; i++) {
        sum = 0;
        for (int j = 0; j < 10; j++) {
            sum += data_[j];
            dp[j] = data_[j] = sum % 10007;
        }
    }
    cout << dp[9];
    return (0);
}