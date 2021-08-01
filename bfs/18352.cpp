#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int N, M, K, X;
    int visited[300001];
	vector<vector<int>> arr(300001);
    // vector<int> arr[300001];
	vector<int> ans;
	queue<pair<int,int> > q;
 
	cin >> N >> M >> K >> X; 
	for (int i = 0; i < M; i++)
	{
        int A, B;
		cin >> A >> B;
		arr[A].push_back(B);
	}
 
	q.push({X, 0});
	visited[X] = 1;
 
	while (!q.empty())
	{
		int now = q.front().first;
		int cost = q.front().second;
		q.pop();
 
		if (cost == K)
			ans.push_back(now);

		for (int i = 0; i < arr[now].size(); i++)
		{
			int next = arr[now][i];
 
			if (!visited[next])
			{
				visited[next] = 1;
				q.push({next, cost + 1});
			}
		}
	}
 
	if (ans.size() == 0) //정답 없으면 -1 출력
		cout << "-1\n";
    else
    {
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << "\n";
    }
	return (0);
}