#include <iostream>
#include <vector>
using namespace std;

int T;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;
	while (T--)
	{
		int N, M, tmp;
		vector<pair<int, int> > printer;

		cin >> N >> M;
		for (int i = 0; i < N; i++)
		{
			cin >> tmp;
			printer.push_back(make_pair(tmp, i));
		}

		int cnt = 1;
		while (!printer.empty())
		{
			int push_check = false;
			int now = printer.front().first;
			int s_idx = printer.front().second;
			printer.erase(printer.begin());
			for (int i = 0; i < printer.size(); i++)
			{
				if (printer[i].first > now)
				{
					printer.push_back(make_pair(now, s_idx));
					push_check = true;
					break ;
				}
			}
			if (!push_check && s_idx == M)
				break ;
			else if (!push_check)
				cnt++;
		}
		cout << cnt << "\n";
	}
	
	return (0);
}