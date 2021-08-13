#include <iostream>
#include <string>
#include <queue>
using namespace std;
 
const int MAX = 101;
 
int M, N;
int dir_x[4] = {1, -1, 0, 0};
int dir_y[4] = {0, 0, 1, -1};
string input[MAX];
bool visited[MAX][MAX];
priority_queue<pair<int, pair<int, int>>> pq;
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> M >> N;

    for (int i = 0; i < N; i++)
        cin >> input[i];

    pq.push({0, {0, 0}});
    visited[0][0] = 1;

    while (!pq.empty())
    {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int wall = pq.top().first * -1;
        pq.pop();

        if (x == N - 1 && y == M - 1)
        {
            cout << wall << "\n";
            break ;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir_x[i];
            int ny = y + dir_y[i];

            if (nx < 0 || nx > N - 1 || ny < 0 || ny > M - 1)
                continue ;

            if (!visited[nx][ny])
            {
                if (input[nx][ny] == '1')
                    pq.push({-(wall + 1), {nx, ny}});
                else
                    pq.push({-wall, {nx, ny}});
                visited[nx][ny] = 1;
            }
        }
    }

    return (0);
}