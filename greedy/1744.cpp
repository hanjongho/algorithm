#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, one_idx = 0, ans = 0;
	int arr[10001];

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	for (int i = 0; i < N; i++)
	{
		one_idx = i;
		if (arr[one_idx] >= 1)
			break ;
	}
	for (int i = 0; i < one_idx - 1; i += 2)
	{
		arr[i] = arr[i] * arr[i + 1];
		arr[i + 1] = 0;
	}
	for (int i = N - 1; i > one_idx; i -= 2)
	{
		arr[i] = max(arr[i] * arr[i - 1], arr[i] + arr[i - 1]);
		arr[i - 1] = 0;
	}
	for (int i = 0; i < N; i++)
		ans += arr[i];
	cout << ans;
	return (0);
}