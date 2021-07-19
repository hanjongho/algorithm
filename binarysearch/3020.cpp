#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

bool compare(int a, int b)
{
	return a > b;
}

int main()
{
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);

	int N, H, size;
	vector<int> v1, v2;
	cin >> N >> H;
	for (int i = 0; i < N; i++)
	{
		cin >> size;
		if (i % 2 == 0)
			v1.push_back(size);
		else
			v2.push_back(size);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	int v1Num, v2Num;
	for (int i = 2; i <= H; i++)
	{
		v1Num = lower_bound(v1.begin(), v1.end(), i) - v1.begin();
		v2Num = lower_bound(v2.begin(), v2.end(), H - i + 1) - v2.begin();
		v.push_back(N - v1Num - v2Num);
	}

	v2Num = lower_bound(v2.begin(), v2.end(), 0) - v2.begin();
	v.push_back((N / 2) - v2Num);

	sort(v.begin(), v.end());
	int idx = upper_bound(v.begin(), v.end(), v[0]) - v.begin();
	cout << v[0] << " " << idx << "\n";
	return (0);
}