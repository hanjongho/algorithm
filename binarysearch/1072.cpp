#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	long long X, Y;
	int ans = -1;

	cin >> X >> Y;

	int percent = (Y * 100) / X;
	if (percent >= 99)
	{
		cout << "-1\n";
		return (0);
	}

	int left = 0, right = 1000000001;
	while (left <= right)
	{
		int n = (left + right) / 2;
		if (percent >= ((100 * (Y + n)) / (X + n)))
			left = n + 1;
		else
			right = n - 1;
	}
	cout << left << "\n";

	return (0);
}