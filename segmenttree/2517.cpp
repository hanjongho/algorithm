#include <iostream>
#include <algorithm>
using namespace std;

int N, power;
int tree[10000000];
pair<int, int> player[500000];

int sum(int idx, int start, int end, int left, int right)
{
    if (right < start || end < left)
		return (0);
    if (left <= start && end <= right) 
        return tree[idx];
    else
        return sum(idx * 2, start, (start + end) / 2, left, right) + 
			   sum(idx * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void update(int idx, int start, int end, int findIdx)
{
    if (findIdx < start || end < findIdx)
		return ;

    if (start == end)
    {
        tree[idx] = 1;
        return ;
    }

    update(idx * 2, start, (start + end) / 2, findIdx);
    update(idx * 2 + 1, (start + end) / 2 + 1, end, findIdx);
    tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}

bool comp(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second < p2.second;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
    for (int i = 0 ; i < N; i++)
	{
		cin >> power;
        player[i].first = i;
        player[i].second = power;
    }

    sort(player, player + N, comp);

    for (int i = 0; i < N; i++)
        player[i].second = i + 1;

    sort(player, player + N);

    for (int i = 0; i < N; i++)
	{
        int curpower = player[i].second;
		cout << i + 1 - sum(1, 1, N, 1, curpower - 1) << "\n";
        update(1, 1, N, curpower);
    }
}