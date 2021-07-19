#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;

int main()
{
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);

	int N, x;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		if (x > 0)
			pq.push(x);
		else if (pq.empty())
			cout << "0\n";
		else if (x == 0)
		{
			cout << pq.top() << "\n";
			pq.pop();
		}
	}

	return (0);
}