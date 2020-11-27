#include <iostream>
using namespace std;

int map[2188][2188], ans[3] = {0,};

int check(int x, int y, int size)
{
	int temp = map[x][y];
	for (int i = x; i < x + size; i++)
		for (int j = y; j < y + size; j++)
			if (map[i][j] != temp)
				return (0);
	if (temp == -1)
		ans[0]++;
	else if (temp == 0)
		ans[1]++;
	else if (temp == 1)
		ans[2]++;
	return (1);
}

void recursive(int x, int y, int size)
{
	if (!check(x, y, size))
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				recursive(x + size/3 * i, y + size/3 * j, size/3);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> map[i][j];
	recursive(1, 1, N);
	for (int i = 0; i < 3; i++)
		cout << ans[i] << "\n";
	return (0);
}