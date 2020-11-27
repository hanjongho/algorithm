#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	char str[100001];
	int i = 0, cnt = 0, ans = 0;
	cin >> str;
	while (str[i])
	{
		if (str[i] == '(' && str[i+1] == ')')
		{
			ans += cnt;
			i++;
		}
		else if (str[i] == '(')
			cnt++;
		else if (str[i] == ')')
		{
			ans++;
			cnt--;
		}
		i++;
	}
	cout << ans;
	return (0);
}