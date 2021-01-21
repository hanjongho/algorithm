#include <iostream>
using namespace std;

int N, result = 2e9;
int map[21][21], selected[21], team_start[11], team_link[11];

void dfs(int position,int cnt) {
    if (cnt == N / 2) {
        int start_idx = 0, start_sum = 0, team_link_idx = 0, team_link_sum = 0;
        for (int i = 0; i < N; i++) {
            if (selected[i])
                team_start[start_idx++] = i;
            else
                team_link[team_link_idx++] = i;
        }
        for (int i = 0; i < N / 2; i++) {
            for (int j = i + 1; j < N / 2; j++) {
                start_sum += map[team_start[i]][team_start[j]] + map[team_start[j]][team_start[i]];
                team_link_sum += map[team_link[i]][team_link[j]] + map[team_link[j]][team_link[i]];
            }
        }
        result = min(result, abs(start_sum - team_link_sum));
        for(int i = 0; i < N / 2; i++)
            team_start[i] = team_link[i] = 0;
    }
    for (int i = position; i < N; i++) {
        if (!selected[i]) {
            selected[i] = 1;
            dfs(i, cnt + 1);
            selected[i] = 0;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> map[i][j];
    dfs(0, 0);
    cout << result;
    return (0);
}
