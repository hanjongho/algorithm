#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, now_idx;
	int arr[40001], dp[40001];
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	dp[1] = arr[1];
	int size = 1;
	for (int i = 2; i <= n; i++)
	{
		if (arr[i] > dp[size])
		{
			size++;
			dp[size] = arr[i];
		}
		else
			dp[lower_bound(dp, dp + size, arr[i]) - dp] = arr[i];
	}
	cout << size;
	return (0);
}