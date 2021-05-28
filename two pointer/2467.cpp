#include <iostream>
#include <algorithm>
using namespace std;

int N, ans = 2e9 + 1, idx1, idx2;
int arr[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	int left = 0, right = N - 1;
	while (left < right)
	{
		int sum = arr[left] + arr[right];
		if (abs(sum) < ans)
		{
			ans = abs(sum);
			idx1 = left;
			idx2 = right;
		}
		if (sum == 0)
			break ;
		if (sum > 0)
			right--;
		else
			left++;
	}
	
	cout << arr[idx1] << " " << arr[idx2] << "\n";
	return (0);
}