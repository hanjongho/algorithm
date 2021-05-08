#include <iostream>
#include <algorithm>
using namespace std;

int N, M, input;
int arr[100001];

int inArray(int input)
{
	int left = 0, right = N - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] == input)
			return (1);
		else if (arr[mid] < input)
			left = mid + 1;
		else if (arr[mid] > input)
			right = mid - 1;
	}
	return (0);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> input;
		cout << inArray(input) << "\n";
	}
	return (0);
}