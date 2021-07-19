#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
int N, ans;
string tmp;
int arr[26];

int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        int cnt = 1;
        for (int j = tmp.size() - 1; j >= 0; j--)
        {
            arr[tmp[j] - 'A'] += cnt;
            cnt *= 10;
        }
    }

    for (int i = 0; i < 26; ++i)
        if (arr[i] != 0)
            v.push_back(arr[i]);	

    sort(v.begin(), v.end());

    int value = 9;
    for (int i = v.size() - 1; i >= 0; i--){
        ans += v[i] * value--;
    }
    cout << ans << "\n";
    return (0);
}