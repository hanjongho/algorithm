#include <iostream>
#include <cstring>
using namespace std;

int visited[100001], haveTeam[100001], wantMember[100001];
	
int dfs(int start, int dest, int cnt)
{
	if (visited[dest])
	{
		if (start != haveTeam[dest])
			return (0);
		return cnt - visited[dest];
	}
	haveTeam[dest] = start;
	visited[dest] = cnt;
	return dfs(start, wantMember[dest], cnt + 1);

	/*
	if (start == dest)
		return (1);
	if (!visited[dest])
	{
		visited[dest] = 1;
		int temp = dfs(start, wantMember[dest]);
		if (temp)
			haveTeam[dest] = 1;
		return temp;
	}
	return (0);
	*/
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int T, n, ans;
	cin >> T;
	while (T--)
	{
		cin >> n;
		ans = 0;
		memset(haveTeam, 0, sizeof(haveTeam));
		memset(wantMember, 0, sizeof(wantMember));
		memset(visited, 0, sizeof(visited));
		for (int i = 1; i <= n; i++)
			cin >> wantMember[i];
		for (int i = 1; i <= n; i++)
			if (!visited[i])
				ans += dfs(i, wantMember[i], 1);
		cout << n - ans << "\n";
	}
	return (0);
}