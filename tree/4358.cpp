#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map<string, int> m;
int cnt = 0;
string str;

int main()
{
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);

	cout << fixed;
	cout.precision(4);

	while (getline(cin, str)) 
	{
		cnt++;
		if (m.find(str) == m.end())
			m.insert({str, 1});
		else
			m[str]++;
	}
	for (auto it = m.begin(); it != m.end(); it++)
		cout << it->first << " " << (it->second / (double)cnt) * 100 << "\n";
	return (0);
}