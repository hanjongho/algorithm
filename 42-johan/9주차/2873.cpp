#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int R,C;
	int arr[1001][1001];
	cin >> R >> C;
	if ((R % 2) && (C % 2)) // 2홀
	{
		for (int i = 1; i <= R; i++)
		{
			for (int j = 1; j < C; j++)
				if (i % 2)
					cout << "R";
				else
					cout << "L";
			if (i != R)
				cout << "D";
		}
	}
	else if ((R + C) % 2) // 1홀 1짝
	{
		int odd, even, flag = 0;
		if (R % 2)
		{
			odd = R;
			even = C;
			flag = 1;
		}
		else
		{
			odd = C;
			even = R;
			flag = 0;
		}
		for (int i = 1; i <= odd; i++)
		{
			for (int j = 1; j < even; j++)
			{
				if (i % 2)
					if (flag)
						cout << "R";
					else
						cout << "D";
				else
					if (flag)
						cout << "L";
					else
						cout << "U";
			}
			if (i != odd)
			{
				if (flag)
					cout << "D";
				else
					cout << "R";
			}
		}
	}
	else // 2짝
	{
		pair<int, int> black;
		int min = 2e9;
		for (int x = 0; x < R; x++)
			for (int y = 0; y < C; y++)
			{
				cin >> arr[x][y];
				if ((x + y) % 2 && min > arr[x][y])
				{
					min = arr[x][y];
					black = make_pair(x, y);
				}
			}
		int newX = black.first % 2 ? black.first - 1 : black.first;
		for (int x = 0; x < newX; x++)
		{
			for (int y = 0; y < C - 1; y++)
				if (x % 2)
					cout << "L";
				else
					cout << "R";
			cout << "D";
		}
		for (int y = 0; y < black.second; y++)
			if (y % 2)
				cout << "UR";
			else
				cout << "DR";
		for (int y = black.second; y < C - 1; y++)
			if (y % 2)
				cout << "RU";
			else
				cout << "RD";
		
		newX = black.first % 2 ? R - (black.first + 1) :  R - (black.first + 2);
		for (int x = 0; x < newX; x++)
		{
			cout << "D";
			for (int y = 0; y < C - 1; y++)
				if (x % 2)
					cout << "R";
				else
					cout << "L";
		}
	}
	return (0);
}