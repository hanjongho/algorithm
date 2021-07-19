#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue<int> pq;
vector<pair<int, int> > v;
vector<int> bag;

int main()
{
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);

	int N, K, weight, value;
	long long ans = 0;
	
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> weight >> value;
		v.push_back(make_pair(weight, value));
	}
	
	for (int i = 0; i < K; i++)
	{
		int tmp;
		cin >> tmp;
		bag.push_back(tmp);
	}

	sort(v.begin(), v.end());
	sort(bag.begin(), bag.end());

	int vIdx = 0;
	for (int i = 0; i < K; i++)
	{
		int bagSize = bag[i];
		while (vIdx < N && v[vIdx].first <= bagSize)
		{
			pq.push(v[vIdx].second);
			vIdx++;
		}
		if (!pq.empty())
		{
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans << "\n";

	return (0);
}