#include <iostream>
#include <algorithm>
using namespace std;

int N, ans = 0;
int arr[2001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
		
	sort(arr, arr + N);
	for (int i = 0; i < N; i++)
	{
		int left = 0, right = N - 1;
		while (left < right)
		{
			int sum = arr[left] + arr[right];
			if (sum == arr[i])
			{
				if (left != i && right != i)
				{
					ans++;
					break ;
				}
				else if (left == i)
					left++;
				else
					right--;
			}
			if (sum > arr[i])
				right--;
			else if (sum < arr[i])
				left++;
		}
	}

	cout << ans << "\n";
	return (0);
}