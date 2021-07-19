#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v1, v2;
long long ans = 0;
int n;
int A[4001], B[4001], C[4001], D[4001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> A[i] >> B[i] >> C[i] >> D[i];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			v1.push_back(A[i] + B[j]);
			v2.push_back(C[i] + D[j]);
		}
	
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	for (int i = 0; i < v1.size(); i++)
	{
		int low = lower_bound(v2.begin(), v2.end(), - v1[i])  - v2.begin();
		int high = upper_bound(v2.begin(), v2.end(), - v1[i]) - v2.begin();
		
		ans += high - low;
	}

	cout << ans << "\n";

	return (0);
}