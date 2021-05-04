#include <iostream>
#include <cstring>
using namespace std;

int T, n, ans;
int selected[100001], haveTeam[100001], wantMember[100001];
	
int dfs(int start, int dest, int cnt)
{
	if (selected[dest])
	{
		if (start != haveTeam[dest])
			return (0);
		return (cnt - selected[dest]);
	}
	haveTeam[dest] = start;
	selected[dest] = cnt;
	return (dfs(start, wantMember[dest], cnt + 1));
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;
	while (T--)
	{
		cin >> n;
		ans = 0;
		memset(haveTeam, 0, sizeof(haveTeam));
		memset(wantMember, 0, sizeof(wantMember));
		memset(selected, 0, sizeof(selected));
		for (int i = 1; i <= n; i++)
			cin >> wantMember[i];
		for (int i = 1; i <= n; i++)
			if (!selected[i])
				ans += dfs(i, wantMember[i], 1);
		cout << n - ans << "\n";
	}
	return (0);
}