#include <iostream>
#include <vector>
using namespace std;

int N, M, ans = 2e9;
int checked[14];
int map[51][51];
vector <pair<int, int> > house, chickenHouse;

void getDistHouseToChickenHouse()
{
	int sum = 0;
	for (int i = 0; i < house.size(); i++)
	{
		int tmp = 2e8;
		for (int j = 0; j < chickenHouse.size(); j++)
		{
			if (checked[j])
			{
				int distX = abs(house[i].first - chickenHouse[j].first);
				int distY = abs(house[i].second - chickenHouse[j].second);
				tmp = tmp > distX + distY ? distX + distY : tmp;
			}
		}
		sum += tmp;
	}
	ans = sum < ans ? sum : ans;
}

void combination(int idx, int cnt)
{
	if (idx > chickenHouse.size() - 1)
		return ;
	if (cnt == M)
	{
		getDistHouseToChickenHouse();
		return ;
	}
	checked[idx + 1] = 1;
	combination(idx + 1, cnt + 1);
	checked[idx + 1] = 0;
	combination(idx + 1, cnt);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
				house.push_back(make_pair(i, j));
			else if (map[i][j] == 2)
				chickenHouse.push_back(make_pair(i, j));
		}
	
	for (int i = 0; i <= chickenHouse.size() - M; i++)
	{
		checked[i] = 1;
		combination(i, 1);
		checked[i] = 0;
	}
	
	cout << ans << "\n";
	return (0);
}