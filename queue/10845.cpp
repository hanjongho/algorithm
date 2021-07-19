#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	queue<int> q;
	int N;
	cin >> N;
	string cmd;

	for (int i = 0; i < N; i++)
	{
		cin >> cmd;
		if (cmd == "push")
		{
			int value;
			cin >> value;
			q.push(value);
		}
		else if (cmd == "pop")
		{
			if (q.size() == 0)
				cout << "-1\n";
			else
			{
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (cmd == "size")
		{
			cout << q.size() << "\n";
		}
		else if (cmd == "empty")
		{
			cout << q.empty() << "\n";
		}
		else if (cmd == "front")
		{
			if (q.size() == 0)
				cout << "-1\n";
			else
				cout << q.front() << "\n";
		}
		else if (cmd == "back")
		{
			if (q.size() == 0)
				cout << "-1\n";
			else
				cout << q.back() << "\n";
		}
	}

	return (0);
}