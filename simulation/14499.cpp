#include <iostream>
using namespace std;

int N, M, x, y, K;
int map[21][21], command[1001], dice[6] = {0, 0, 0, 0, 0, 0};

void moveDice(int dir)
{
    int tmp;
    if (dir == 1)
    {
        tmp = dice[0];
        dice[0] = dice[3];
        dice[3] = dice[5];
        dice[5] = dice[1];
        dice[1] = tmp;
    }
    else if (dir == 2)
    {
        tmp = dice[0];
        dice[0] = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[3];
        dice[3] = tmp;
    }
    else if (dir == 3)
    {
        tmp = dice[0];
        dice[0] = dice[4];
        dice[4] = dice[5];
        dice[5] = dice[2];
        dice[2] = tmp;
    }
    else if (dir == 4)
    {
        tmp = dice[0];
        dice[0] = dice[2];
        dice[2] = dice[5];
        dice[5] = dice[4];
        dice[4] = tmp;
    }
    if (!map[x][y])
        map[x][y] = dice[5];
    else
    {
        dice[5] = map[x][y];
        map[x][y] = 0;
    }
    cout << dice[0] << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> x >> y >> K;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> map[i][j];
    for (int k = 0; k < K; k++)
        cin >> command[k];
    for (int i = 0; i < K; i++)
    {
        if (command[i] == 1)
        {
            if (y + 1 > M - 1) continue;
            y += 1;
            moveDice(1);
        }
        else if (command[i] == 2)
        {
            if (y - 1 < 0) continue;
            y -= 1;
            moveDice(2);
        }
        else if (command[i] == 3)
        {
            if (x - 1 < 0) continue;
            x -= 1;
            moveDice(3);
        } 
        else if (command[i] == 4)
        {
            if (x + 1 > N - 1) continue;
            x += 1;
            moveDice(4);
        }
    }
    return (0);
}