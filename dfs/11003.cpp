#include <iostream>
#include <deque>
using namespace std;

int N, L, a;
deque <pair<int, int> > dq;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> L;
    for (int i = 1; i <= N ; i++)
	{
		cin >> a;
        while (!dq.empty())
		{
			// 들어오려는게 가장 작으면 그 전에 큰 얘들 전부 아웃
            if (dq.back().second >= a)
				dq.pop_back();
            else
				break;
        }
        dq.push_back({i, a});

		// 범위 안들면 아웃
        if (dq.front().first == i - L)
			dq.pop_front();

		cout << dq.front().second << " ";

		// cout << "  -----" << dq.front().first << " " << i - L << " ~ " << i << " 큐 현황-----\n";

		// cout << dq.front().second << " ";
		// for (int i = 0; i < dq.size(); i++)
		// {
		// 	pair<int, int> tmp = dq[i];
		// 	cout << "{" << tmp.first << "," << tmp.second << "} ";
		// }
		// cout << "\n  --------------------------\n\n";
    }
	return (0);
}