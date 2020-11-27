#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<pair<int, int> > graph[100001];
int V, diameter = 0, farthestNode = 0;
int visited[100001];

void dfs(int node, int cost)
{
	if (visited[node])
		return ;
	visited[node] = 1;
	if (diameter < cost)
	{
		diameter = cost;
		farthestNode = node;
	}
	for (int i = 0; i < graph[node].size(); i++)
		dfs(graph[node][i].first, cost + graph[node][i].second);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin >> V;
	for (int i = 0; i < V; i++)
	{
		int node, node2, cost;
		cin >> node;
		while (1)
		{
			cin >> node2;
			if (node2 == -1)
				break ;
			cin >> cost;
			graph[node].push_back(make_pair(node2, cost));
		}
	}
	dfs(1, 0);
	memset(visited, 0, sizeof(visited));
	diameter = 0;
	dfs(farthestNode, 0);
	cout << diameter << "\n";
	return (0);
}