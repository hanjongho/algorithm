#include <iostream>
using namespace std;

int maxN = -1000000001, minN = 1000000001;
int N, arr[12], p, s, m, d;

void recursive(int index, int plus, int sub, int multi, int divi, int total) {
    if (index == N-1) {
        if(total > maxN)
            maxN = total;
        if(total < minN)
            minN = total;
        return ;
    }
    if (plus < p)
        recursive(index + 1, plus + 1, sub, multi, divi, total + arr[index + 1]);
    if (sub < s)
        recursive(index + 1, plus, sub + 1, multi, divi, total - arr[index + 1]);
    if (multi < m)
        recursive(index + 1, plus, sub, multi + 1, divi, total * arr[index + 1]);
    if (divi < d)
        recursive(index + 1, plus, sub, multi, divi + 1, total / arr[index + 1]);
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    cin >> p >> s >> m >> d;
    recursive(0, 0, 0, 0, 0, arr[0]);
    cout << maxN << "\n" << minN << "\n";
    return (0);
}