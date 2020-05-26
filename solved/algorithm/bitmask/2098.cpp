#include <iostream>
#include <cstring>
#define MAX 16
#define INF 987654321
using namespace std;

int N;
int W[MAX][MAX], cache[MAX][1 << MAX];
int TSP(int current, int visited){
    if (visited == (1 << N) - 1)
        if(W[current][0] != 0)
            return W[current][0];

    int &result = cache[current][visited];
    if (result != -1)
        return result;
    result = INF;
    for (int next = 0; next < N; next++){
        // 이미 방문했거나, 갈 수 없는 경우
        if (visited & (1 << next) || W[current][next] == 0)
            continue;
        result = min(result, W[current][next] + TSP(next, visited + (1 << next)));
    }
    return result;
}

int main(){
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> W[i][j];
    memset(cache, -1, sizeof(cache));
    cout << TSP(0, 1);
    return 0;
}
