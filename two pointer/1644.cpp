#include <iostream>
#include <vector>
using namespace std;

int N, ans = 0, low = 0, high = 0;
int arr[4000001];
vector<int> prime;

void eratosthenes()
{
	for (int i = 2; i < 4000001; i++)
		arr[i] = i;

	for (long long i = 2; i < 4000001; i++)
		if (arr[i] == i)
			for (long long j = i * 2; j < 4000001; j += i)
				arr[j] = 0;

	for (int i = 2; i < 4000001; i++)
		if (arr[i] == i)
			prime.push_back(i);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	
	eratosthenes();
	int sum = prime[0];
	while (low <= high && high < prime.size() && prime[low] <= N)
	{
		if (sum == N)
			ans++;
		if (sum <= N)
			sum += prime[++high];
		else if (sum > N)
		{
			sum -= prime[low++];
			if (low > high && low < prime.size())
			{
				high = low;
				sum = prime[low];
			}
		}
	}

	cout << ans << "\n";

	return (0);
}