#include <iostream>
#include <algorithm>
using namespace std;

int N, C;
int house[200001];

bool possible(int dist)
{
	int cnt = 1;
	int prev = house[0];
	for(int i = 1; i < N; i++)
		if (house[i] - prev >= dist)
		{
			cnt++;
			prev = house[i];
		}
	if (cnt >= C)
		return (1);
	return (0);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> C;
	for (int i = 0; i < N; i++)
		cin >> house[i];
	sort(house, house + N);
	int low = 1, high = house[N - 1] - house[0], ans = 0;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (possible(mid))
		{
			ans = max(ans, mid);
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	cout << ans << "\n";
	return (0);
}