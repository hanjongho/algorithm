#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int N, K, cnt = 0;
	int coin[10];

	cin >> N >> K;
	for(int i = 0; i < N; i++)
		cin >> coin[i];
	for (int i = N - 1; i >= 0 && K != 0; i--) {
		cnt += K / coin[i];
		K %= coin[i];
	}
	cout << cnt;
	return (0);
}