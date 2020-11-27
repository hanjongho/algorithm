#include <iostream>
using namespace std;

void disk(int N, int first, int second, int third)
{
    if(N == 1)
		cout << first << " " << third << "\n";
    else
    {
        disk(N - 1, first, third, second);
		cout << first << " " << third << "\n";
        disk(N - 1, second, first, third);
    }
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	cout << (1 << N) -1 << "\n";
    disk(N, 1, 2, 3);
	return (0);
}