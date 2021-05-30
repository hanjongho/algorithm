#include <iostream>
#include <algorithm>
using namespace std;

int N, sum = 0, ans = 2e9 + 1, ans_left, ans_right;
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
		sum = arr[left] + arr[right];
		if (abs(sum) < ans)
		{
			ans = abs(sum);
			ans_left = left;
			ans_right = right;
		}
		if (sum == 0)
			break ;
		if (sum > 0)
			right--;
		else if (sum < 0)
			left++;
	}
	
	cout << arr[ans_left] << " " << arr[ans_right] << "\n";
	return (0);
}