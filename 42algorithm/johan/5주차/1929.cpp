#include <iostream>
using namespace std;

int	is_prime(int n)
{
	int i;

	if (n < 2)
		return (0);
	i = 2;
	while (i <= n / 2 && i <= 65536)
		if (n % i++ == 0)
			return (0);
	return (1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int M, N;
	
	cin >> M >> N;
	for (int i = M; i <= N; i++)
		if (is_prime(i))
			cout << i << "\n";
	return (0);
}