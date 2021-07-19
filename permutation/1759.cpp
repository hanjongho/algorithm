#include <iostream>
#include <algorithm>
using namespace std;

int L, C;
char alphabet[26];
int selected[26];

void dfs(int idx, int cnt)
{
	if (cnt == L)
	{
		int tmp = 0;
		for (int i = 0; i < C; i++)
			if (selected[i])
			{
				if (alphabet[i] == 'a'
				|| alphabet[i] == 'e'
				|| alphabet[i] == 'i'
				|| alphabet[i] == 'o'
				|| alphabet[i] == 'u')
				tmp++;
			}
		if (tmp >= 1 && L - tmp >= 2)
		{
			for (int i = 0; i < C; i++)
				if (selected[i])
					cout << alphabet[i];
			cout << "\n";
		}
		return ;
	}

	for (int i = idx; i < C; i++)
	{
		selected[i] = 1;
		dfs(i + 1, cnt + 1);
		selected[i] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> L >> C;

	for (int i = 0; i < C; i++)
		cin >> alphabet[i];

	sort(alphabet, alphabet + C);

	dfs(0, 0);
}