#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	stack<int> s;
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
			s.push(value);
		}
		else if (cmd == "pop")
		{
			if (s.size() == 0)
				cout << "-1\n";
			else
			{
				cout << s.top() << "\n";
				s.pop();
			}
		}
		else if (cmd == "size")
		{
			cout << s.size() << "\n";
		}
		else if (cmd == "empty")
		{
			cout << s.empty() << "\n";
		}
		else if (cmd == "top")
		{
			if (s.size() == 0)
				cout << "-1\n";
			else
				cout << s.top() << "\n";
		}
	}

	return (0);
}