#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, tmp;
	
	cin >> N;
	short nums[10002] = {0,};
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		nums[tmp]++;
	}
	for (int i = 1; i <= 10000; i++) {
		if (nums[i] == 0)
			continue;
		for (short j = 0; j < nums[i]; j++)
			cout << i << "\n";
	}
	return (0);
}