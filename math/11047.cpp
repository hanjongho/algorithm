#include <iostream>
using namespace std;

int n, k, cnt;
int coin[10];

int main()
{
	cin >> n >> k;
    for (int i = 0; i < n; i++) 
		cin >> coin[i];
    for (int i = n - 1; i >= 0 && k != 0; i--) 
        if (coin[i] <= k) {
            cnt += k / coin[i];
            k -= k / coin[i] * coin[i];
        }
	cout << cnt;
}