#include <iostream>
#include <queue>
using namespace std;

int gear[5][9];

void gearRotate(int num, int dir)
{
	if (dir == -1)
	{
		int tmp = gear[num][0];
		for (int i = 0; i < 7; i++)
			gear[num][i] = gear[num][i + 1];
		gear[num][7] = tmp;
	}
	else if (dir == 1)
	{
		int tmp = gear[num][7];
		for (int i = 7; i > 0; i--)
			gear[num][i] = gear[num][i - 1];
		gear[num][0] = tmp;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int K, gear_num, dir, sum = 0;
	queue<pair<int, int> > q1;
	string t1, t2, t3, t4;

	cin >> t1 >> t2 >> t3 >> t4;
	for (int j = 0; j < 8; j++) {
		gear[1][j] = t1[j] - '0';
		gear[2][j] = t2[j] - '0';
		gear[3][j] = t3[j] - '0';
		gear[4][j] = t4[j] - '0';
	}
	cin >> K;
	while (K--) {
		cin >> gear_num >> dir;
		if (gear_num == 1)
		{
			if (gear[1][2] != gear[2][6])
			{
				dir *= -1;
				if (gear[2][2] != gear[3][6])
				{
					dir *= -1;
					if (gear[3][2] != gear[4][6])
						gearRotate(4, dir * -1);
					gearRotate(3, dir);
					dir *= -1;
				}
				gearRotate(2, dir);
				dir *= -1;
			}
			gearRotate(1, dir);
		}
		else if (gear_num == 2)
		{
			if (gear[2][6] != gear[1][2])
				gearRotate(1, dir * -1);
			if (gear[2][2] != gear[3][6])
			{
				dir *= -1;
				if (gear[3][2] != gear[4][6])
					gearRotate(4, dir * -1);
				gearRotate(3, dir);
				dir *= -1;
			}
			gearRotate(2, dir);
		}
		else if (gear_num == 3)
		{
			if (gear[3][2] != gear[4][6])
				gearRotate(4, dir * -1);
			if (gear[3][6] != gear[2][2])
			{
				dir *= -1;
				if (gear[2][6] != gear[1][2])
					gearRotate(1, dir * -1);
				gearRotate(2, dir);
				dir *= -1;
			}
			gearRotate(3, dir);
		}
		else if (gear_num == 4)
		{
			if (gear[4][6] != gear[3][2])
			{
				dir *= -1;
				if (gear[3][6] != gear[2][2])
				{
					dir *= -1;
					if (gear[2][6] != gear[1][2])
						gearRotate(1, dir * -1);
					gearRotate(2, dir);
					dir *= -1;
				}
				gearRotate(3, dir);
				dir *= -1;
			}
			gearRotate(4, dir);
		}
	}
	if (gear[1][0]) sum += 1;
	if (gear[2][0]) sum += 2;
	if (gear[3][0]) sum += 4;
	if (gear[4][0]) sum += 8;
	cout << sum << "\n";
	return (0);
}
