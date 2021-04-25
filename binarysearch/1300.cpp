#include <iostream>
using namespace std;

int N, K, j;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> K;

	int start = 1, end = K;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		j = 0;
		for (int i = 1; i <= N; i++)
			j += min(mid / i, N);
		if (j < K)
			start = mid + 1;
		else
			end = mid - 1;
	}

	cout << start << "\n";
	return (0);
}