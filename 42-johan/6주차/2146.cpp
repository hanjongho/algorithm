#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N;
int board[101][101], visited[101][101];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int x, int y, int count) {
    board[x][y] = count;
    visited[x][y] = 1;
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < N && 0 <= ny && ny < N)
            if (board[nx][ny] && !visited[nx][ny])
                dfs(nx, ny, count);
    }
}

int bfs(int count) {
    queue<pair<int, int> > q;
    int distance = 0;

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            if (board[x][y] == count) {
                visited[x][y] = 1;
                q.push(make_pair(x, y));
            }
        }
    }
    
    while (!q.empty()) {
        int q_size = q.size();
        for (int i = 0; i < q_size; i++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                if (0 <= nx && nx < N && 0 <= ny && ny < N) {
                    if (board[nx][ny] != 0 && board[nx][ny] != count)
                        return distance;
                    else if (board[nx][ny] == 0 && !visited[nx][ny]) {
                        visited[nx][ny] = 1;
                        q.push(make_pair(nx,ny));
                    }         
                }
            }
        }
        distance++;
    }
    return (0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

    int count = 1, result = 987654321;
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (board[i][j] && !visited[i][j])
                dfs(i, j, count++);
    
    for (int i = 1; i < count; i++){
        memset(visited, 0, sizeof(visited));
        result = min(result, bfs(i));
    }
    
    cout << result;
    return (0);
}