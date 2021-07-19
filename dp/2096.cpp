#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, min_ = 2e9, max_ = -1;
	int arr[100001][3];
	queue <pair<int, pair<int, int> > > q;

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	
	q.push({arr[0][0], {0, 0}});
	q.push({arr[0][1], {0, 1}});
	q.push({arr[0][2], {0, 2}});

	while (!q.empty())
	{
		int sum = q.front().first;
		int idx = q.front().second.first;
		int num = q.front().second.second;
		q.pop();
		
		if (idx == N - 1)
		{
			if (sum > max_)
				max_ = sum;
			if (sum < min_)
				min_ = sum;
			continue ;
		}
		
		if (num == 0)
		{
			q.push({sum + arr[idx + 1][0], {idx + 1, 0}});
			q.push({sum + arr[idx + 1][1], {idx + 1, 1}});
		}
		else if (num == 1)
		{
			q.push({sum + arr[idx + 1][0], {idx + 1, 0}});
			q.push({sum + arr[idx + 1][1], {idx + 1, 1}});
			q.push({sum + arr[idx + 1][2], {idx + 1, 2}});
		}
		else if (num == 2)
		{
			q.push({sum + arr[idx + 1][1], {idx + 1, 1}});
			q.push({sum + arr[idx + 1][2], {idx + 1, 2}});
		}
	}
	cout << max_ << " " << min_ << "\n";
	return (0);
}