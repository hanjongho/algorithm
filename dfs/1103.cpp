#include <iostream>
using namespace std;

int N, M, ans, cycleCheck;
int dir_y[4] = {-1, 1, 0, 0};
int dir_x[4] = {0, 0, -1, 1};
int visitNum[51][51]; 
char board[51][51];

void dfs(int x, int y, int cnt)
{
    if (ans < cnt)
		ans = cnt;
    if (ans > cycleCheck || board[x][y] == -1)
		return ;
    if (x < 0 || x > N - 1 || y < 0 || y > M - 1)
		return ;
	if (cnt <= visitNum[x][y])
		return ;
    visitNum[x][y] = cnt;

    for (int i = 0; i < 4; i++)
        dfs(x + dir_x[i] * board[x][y], y + dir_y[i] * board[x][y], cnt + 1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
    cycleCheck = N * M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            visitNum[i][j] = -1;

	string tmp;
    for (int i = 0; i < N; i++)
	{
		cin >> tmp;
        for (int j = 0; j < tmp.size(); j++)
		{
			board[i][j] = tmp[j];
            if (board[i][j] == 'H')
				board[i][j] = -1;
            else 
				board[i][j] -= '0';
        }
    }
    dfs(0, 0, 0);
    if (ans > cycleCheck)
		ans = -1;
	cout << ans << "\n";
	return (0);
}