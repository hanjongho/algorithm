#include <iostream>
using namespace std;

int main()
{
    int N;
    int score[301] ={0, }, stair[301][3] = {0, };

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> score[i];
    stair[1][1] = score[1];
    stair[1][2] = 0;
    stair[2][1] = score[2];
    stair[2][2] = stair[1][1] + score[2];
    for (int i = 3; i <= N; i++)
    {
        stair[i][1] = max(stair[i - 2][1], stair[i - 2][2]) + score[i];
        stair[i][2] = max(stair[i - 2][1], stair[i - 1][1]) + score[i];
    }
    cout << max(stair[N][1], stair[N][2]);
}