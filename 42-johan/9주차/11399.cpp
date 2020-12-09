#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int N, ans = 0;
	int person[1001];

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> person[i];
	sort(person, person + N);
	for (int i = 0; i < N; i++)
		ans += person[i] * (N - i);
	cout << ans << endl;
	return (0);
}

