#include <iostream>
using namespace std;

int ans(int n, int x)
{
	int ans = 0;

	for (long long i = x; i <= n; i *= x)
		ans += n / i;
	return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, two = 0, five = 0;

	cin >> n >> m;
	two = ans(n, 2) - ans(n - m, 2) - ans(m, 2);
	five = ans(n, 5) - ans(n - m, 5) - ans(m, 5);
	cout << min(two, five);
	return (0);
}