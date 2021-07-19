#include <iostream>
using namespace std;

int idx;
int tree[40004];

void postOrder(int start, int end)
{
	if (start == end)
		return ;

	int idx = start + 1;
	while (idx < end && tree[idx] < tree[start])
		idx++;

	postOrder(start + 1, idx);
	postOrder(idx, end);
	cout << tree[start] << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (idx = 0; cin >> tree[idx]; idx++);

	postOrder(0, idx);

	return (0);
}