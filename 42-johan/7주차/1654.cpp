#include <iostream>
using namespace std;

int N, K;
long long lan[10001];

void diviedandconquer(long long start, long long end)
{
	long long mid = (start + end) / 2;
	long long sum = 0;
	for (int i = 0; i < N; i++)
		sum += lan[i] / mid;
	if (start > end)
		cout << end << "\n";
	else if (sum < K)
		diviedandconquer(start, mid - 1);
	else if (sum >= K)
		diviedandconquer(mid + 1, end);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;
	long long right = 0;

	for (int i = 0; i < N; i++) {
		cin >> lan[i];
		right = max(right, lan[i]);
	}
	diviedandconquer(1, right);
	return (0);
}