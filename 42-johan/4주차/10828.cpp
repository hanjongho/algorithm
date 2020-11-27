#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a, b, dir = 0;
	char chr[10];
	int stack[15000];

	cin >> a;
	for (int i = 0; i < a; i++) {
		cin >> chr;
		if (!strcmp(chr, "push")){
			cin >> b;
			stack[dir] = b;
			dir++;
		}
		else if (!strcmp(chr, "pop")) {
			if (dir == 0)
				cout << "-1\n";
			else {
				cout << stack[dir-1] << "\n";
				stack[dir] = 0;
				dir--;
			}
		}
		else if (!strcmp(chr, "size"))
			cout << dir << "\n";
		else if (!strcmp(chr, "empty")) {
			if (dir == 0)
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (!strcmp(chr, "top")) {
			if (dir == 0)
				cout << "-1\n";
			else
				cout << stack[dir-1] << "\n";
		}
	}
	return (0);
}