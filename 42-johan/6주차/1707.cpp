#include <iostream>
#include <vector>
#include <queue> 
#include <cstring>
using namespace std;

int K, V, E, a, b; 
vector<int> graph[20001];
int visited[20001];

void bfs(int start)
{
    queue<int> q;
 
    visited[start] = 1;
    q.push(start);
    while (!q.empty())
	{
        int now = q.front();
        q.pop();
        for (int i = 0; i < graph[now].size(); i++)
		{
            int next = graph[now][i];
            if (visited[next] == -1) {
                visited[next] = visited[now] ? 0 : 1;
                q.push(next);
            }
        }
    }
}
 
int checkGraph()
{
    for (int i = 1; i <= V; i++)
	{
        for (int j = 0; j < graph[i].size(); j++)
		{
            int next = graph[i][j];
            if (visited[i] == visited[next])
                return (0);
        }
    }
    return (1);
}
 
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin >> K;
    while (K--)
	{
        for (int i = 0; i <= V; i++)
            graph[i].clear();
        memset(visited, -1, sizeof(visited));
		cin >> V >> E;
        for (int i = 0; i < E; i++)
		{
			cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for (int i = 1; i <= V; i++)
            if (visited[i] == -1)
                bfs(i);
        if (checkGraph())
			cout << "YES\n";
        else 
			cout << "NO\n";
    }
    return (0);
}
