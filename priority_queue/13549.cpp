#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;
 
int visited[MAX];
 
int main()
{
    int N, K;
    cin >> N >> K;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, N});
    visited[N] = 1;

    while (!pq.empty())
    {
        int sec = pq.top().first;
        int x = pq.top().second;
        pq.pop();

        if (x == K)
        {   
            cout << sec << "\n";
            break ;
        }

        if (x * 2 < MAX && !visited[x * 2])
        {
            pq.push({sec, x * 2});
            visited[x * 2] = 1;
        }
        if (x + 1 < MAX && !visited[x + 1])
        {
            pq.push({sec + 1, x + 1});
            visited[x + 1] = 1;
        }
        if (x - 1 >= 0 && !visited[x - 1])
        {
            pq.push({sec + 1, x - 1});
            visited[x - 1] = 1;
        }
    }

    return (0);
}
