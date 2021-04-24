#include <iostream>
#include <vector>
using namespace std;

int n, num = 1, goal_idx = 1, stack_idx = 1, flag = false;
int goal[100001], stack[100001];
vector<char> ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> goal[i];

	while (num <= n || stack_idx > 1)
	{
		if (goal[goal_idx] >= num)
		{
			ans.push_back('+');
			stack[stack_idx] = num;
			stack_idx++;
			num++;
		}
		else if (goal[goal_idx] < num)
		{
			if (stack[stack_idx - 1] != goal[goal_idx])
			{
				flag = 1;
				break ;
			}
			ans.push_back('-');
			stack_idx--;
			goal_idx++;
		}
	}
	if (flag)
		cout << "NO\n";
	else
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << "\n";

	return (0);
}