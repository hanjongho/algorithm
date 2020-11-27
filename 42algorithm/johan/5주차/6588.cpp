#include <iostream>
using namespace std;

int prime[1000001];
int	is_prime(int n)
{
	int i;

	if (n < 2)
		return (0);
	i = 2;
	while (i <= n / 2 && i <= 1000)
		if (n % i++ == 0)
			return (0);
	return (1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	for(int i = 2; i <= 1000000; i++)
		prime[i] = is_prime(i);
	while(1)
	{
		cin >> n;
		if (!n) break;
		for (int i = 2; i < n; i++)
		{
			if (prime[i])
			{
				if (prime[n - i])
				{
					cout << n << " = " << i << " + " << n - i << "\n";
					break ;
				}
			}
		}
	}
	return (0);
}