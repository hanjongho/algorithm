#include <iostream>
using namespace std;

int map[65][65];

void recursive(int x, int y, int size)
{
    int temp = map[x][y];
    for (int i = x; i < x + size; i++)
    {
        for (int j = y; j < y + size; j++)
        {
            if (temp != map[i][j])
            {
                cout << "(";
                recursive(x, y, size / 2);
                recursive(x, y + size / 2, size / 2);
                recursive(x + size / 2, y, size / 2);
                recursive(x + size / 2, y + size / 2, size / 2);
                cout << ")";
				return ;
            }
        }
    }
    cout << temp;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N;
    cin >> N;

    char a;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> a;
            map[i][j] = a - '0';
        }
    }
	recursive(1, 1, N);
	return (0);
}