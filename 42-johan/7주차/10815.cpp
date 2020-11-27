#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int card[500001], check[500001];

void daq(int find)
{
	int start = 0, end = N - 1, mid = 0;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (find < card[mid])
			end = mid - 1;
		else
			start = mid + 1;
	}
	if (find == card[end])
		cout << "1 ";
	else
		cout << "0 ";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> card[i];
	cin >> M;
	for (int i = 0; i < M; i++)
		cin >> check[i];
	sort(card, card + N);
	for (int i = 0; i < M; i++)
		daq(check[i]);
	return (0);
}