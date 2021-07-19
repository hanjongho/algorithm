#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, S, min_ = 2e9;
	int arr[100001];

	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int left = 0, right = 0;
	int sum = arr[left];

	while (left <= right && right < N)
	{
		if (sum >= S)
		{
			if (right - left + 1 < min_)
				min_ = right - left + 1;
			sum -= arr[left++];
			if (left > right && left < N)
			{
				right = left;
				sum = arr[right];
			}
		}
		else
			sum += arr[++right];
	}
	if (min_ == 2e9)
		cout << "0\n";
	else
		cout << min_ << "\n";

	return (0);
}