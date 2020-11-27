#include <iostream>
using namespace std;

int N, M;
long long tree[1000001];

void daq(long long start, long long end)
{
	long long mid = (start + end) / 2;
	long long sum = 0;
	for (int i = 0; i < N; i++)
		if (mid < tree[i])
			sum += tree[i] - mid;
	if (start > end)
		cout << end << "\n";
	else if (sum < M)
		daq(start, mid - 1);
	else if (sum >= M)
		daq(mid + 1, end);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	long long max_ = -1;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> tree[i];
		max_ = max(max_, tree[i]);
	}
	daq(1, max_);
	return (0);
}