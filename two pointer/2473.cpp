#include <iostream>
#include <algorithm>
using namespace std;

int N, idx1, idx2, idx3;
long long minimum = 3e10 + 1;
long long arr[5001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);
	for (int left = 0; left < N; left++)
	{
		int mid = left + 1, right = N - 1;
		while (mid < right)
		{
			long long sum = arr[left] + arr[mid] + arr[right];
			if (abs(sum) < minimum)
			{
				minimum = abs(sum);
				idx1 = left;
				idx2 = mid;
				idx3 = right;
			}
			if (sum == 0)
				break ;
			if (sum > 0)
				right--;
			else
				mid++;
		}
	}

	cout << arr[idx1] << " " << arr[idx2] << " " << arr[idx3] << "\n";
	return (0);
}