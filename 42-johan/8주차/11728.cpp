#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int A, B;
	int a[1000001], b[1000001];

	cin >> A >> B;
	for (int i = 0; i < A; i++)
		cin >> a[i];
	for (int i = 0; i < B; i++)
		cin >> b[i];
	int i = 0, j = 0;
	while (i + j < A + B)
	{
		if (i == A)
			cout << b[j++] << " ";
		else if (j == B)
			cout << a[i++] << " ";
		else
		{
			if (a[i] < b[j])
				cout << a[i++] << " ";
			else if (b[j] <= a[i])
				cout << b[j++] << " ";
		}
	}
	return (0);
}