#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, power;
pair<int, int> player[500000];
int tr[10000000];

int seg_sum(int treeIdx, int s, int e, int l, int r)
{
    if (r < s || e < l)
		return (0);
    if (l <= s && e <= r) 
        return tr[treeIdx];
    else
        return seg_sum(treeIdx * 2, s, (s + e) / 2, l, r) + 
			   seg_sum(treeIdx * 2 + 1, (s + e) / 2 + 1, e, l, r);
}

void update(int treeIdx, int s, int e, int idx)
{
    if (idx < s || e < idx)
		return ;
    if (s == e)
        tr[treeIdx] = 1;
    else
	{
        update(treeIdx * 2, s, (s + e) / 2, idx);
        update(treeIdx * 2 + 1, (s + e) / 2 + 1, e, idx);
        tr[treeIdx] = tr[treeIdx * 2] + tr[treeIdx * 2 + 1];
    }
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
		cout << i + 1 - seg_sum(1, 1, N, 1, curpower - 1) << "\n";
        update(1, 1, N, curpower);
    }
}