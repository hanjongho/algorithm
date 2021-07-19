#include <iostream>
#include <vector>
using namespace std;

int N, K, result = 0;
int selected[26];
vector<string> word;

void permutation(int idx, int cnt)
{
	if (cnt == K - 5)
	{
		int tmp = 0;
		for (int i = 0; i < N; i++)
		{
			bool canRead = 1;
			for(int j = 0; j < word[i].size(); j++)
			{
				if (!selected[word[i][j] - 'a'])
				{
					canRead = 0;
					break ;
				}
			}
			if (canRead)
				tmp++;
		}
		result = max(result, tmp);
		return ;
	}

	for (int i = idx; i < 26; i++)
	{
		if (!selected[i])
		{
			selected[i] = 1;
			permutation(i, cnt + 1);
			selected[i] = 0;
		}
	}
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;
	if (K < 5)
		cout << result << "\n";
	else if (K == 26)
		cout << N << "\n";
	else
	{	
		for (int i = 0; i < N; i++)
		{
			string tmp;
			cin >> tmp;
			word.push_back(tmp.substr(4, tmp.length() - 8));
		}
		selected['a' - 'a'] = 1;
        selected['n' - 'a'] = 1;
        selected['t' - 'a'] = 1;
        selected['i' - 'a'] = 1;
        selected['c' - 'a'] = 1;

		permutation(0, 0);
		cout << result << "\n";
	}

    return 0;
}