#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
long long ans = 4e10 + 1;
long long arr[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	
	int left = 0, right = 0;
	while (right < N)
	{
		long long dist = arr[right] - arr[left];
		if (abs(dist) >= M && abs(dist) < ans)
			ans = abs(dist);
		if (dist == M)
			break ;
		if (dist < M)
			right++;
		else if (dist > M)
			left++;
	}

	cout << ans << "\n";
	return (0);
} 