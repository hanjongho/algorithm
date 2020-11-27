#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, two = 0, five = 0;

	cin >> N;

    for (int i = 2; i <= N; i *= 2)
        two += N / i;
	for (int i = 5; i <= N; i *= 5)
        five += N / i;
	cout << min(two, five);
	return (0);
}