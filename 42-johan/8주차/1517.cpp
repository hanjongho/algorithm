#include <iostream>
using namespace std;

int arr[500001], arr2[500001];
long long recursive(int start, int end)
{
	if (start == end)
		return (0);
	int mid = (start + end) / 2;
	long long result = recursive(start, mid) + recursive(mid + 1, end);
	int i = start;
	int j = mid + 1;
	int idx = 0;
	while (i <= mid || j <= end)
	{
		if (i <= mid && (j > end || arr[i] <= arr[j]))
				arr2[idx++] = arr[i++];
		else
		{
			result += (mid - i + 1);
			arr2[idx++] = arr[j++];
		}
	}
	for (int k = start; k <= end; k++)
		arr[k] = arr2[k - start];
	return (result);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int N;

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	cout << recursive(0, N - 1) << "\n";
	return (0);
}