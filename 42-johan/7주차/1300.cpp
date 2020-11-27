#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int N, K;
	
	cin >> N >> K;
	int start = 1, end = K;
	while (start <= end)
	{
		int cnt = 0;
		int mid = (start + end) / 2;
		for (int i = 1; i <= N; i++)
			cnt += min(mid / i, N);
		if (cnt < K)
			start = mid + 1;
		else
			end = mid - 1;
	}
	cout << start << "\n";
	return (0);
}