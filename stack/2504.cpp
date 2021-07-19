#include <iostream>
#include <stack>
using namespace std;
 
stack<char> s;
string str;
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> str;

	long long result = 0;
	int temp = 1;
	bool isOk = 1;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
		{
			temp *= 2;
			s.push('(');
		}
		else if (str[i] == '[')
		{
			temp *= 3;
			s.push('[');
		}
		else if (str[i] == ')')
		{
			if ((s.empty() || s.top() != '('))
			{
				isOk = 0;
				break ;
			}
			if (str[i - 1] == '(')
				result += temp;
			s.pop();
			temp /= 2;
		}
		else if (str[i] == ']')
		{
			if ((s.empty() || s.top() != '['))
			{
				isOk = 0;
				break ;
			}
			if (str[i - 1] == '[')
				result += temp;
			s.pop();
			temp /= 3;
		}
	}

	if (!isOk || !s.empty())
		cout << "0\n";
	else
		cout << result << "\n";
	return (0);
}