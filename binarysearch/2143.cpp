#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	vector<long long> v1, v2;
	long long T, ans = 0;
	int N, M;
	int arr[1001], brr[1001];

	cin >> T;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	cin >> M;
	for (int i = 0; i < M; i++)
		cin >> brr[i];


	for (int i = 0; i < N; i++)
	{
		long long sum = arr[i];
		v1.push_back(sum);
		for (int j = i + 1; j < N; j++)
		{
			sum += arr[j];
			v1.push_back(sum);
		}
	}

	for (int i = 0; i < M; i++)
	{
		long long sum = brr[i];
		v2.push_back(sum);
		for (int j = i + 1; j < M; j++)
		{
			sum += brr[j];
			v2.push_back(sum);
		}
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	for (int i = 0; i < v1.size(); i++)
	{
		int low = lower_bound(v2.begin(), v2.end(), T - v1[i])  - v2.begin();
		int high = upper_bound(v2.begin(), v2.end(), T - v1[i]) - v2.begin();

		ans += high - low;
	}

	cout << ans << "\n";
	return (0);
}