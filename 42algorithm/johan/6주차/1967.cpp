#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<pair<int, int> > graph[10001];
int n, diameter = 0, farthestNode = 0;
int visited[10001];

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
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int node, node2, cost;
		cin >> node >> node2 >> cost;
		graph[node].push_back(make_pair(node2, cost));
		graph[node2].push_back(make_pair(node, cost));
	}
	dfs(1, 0);
	memset(visited, 0, sizeof(visited));
	diameter = 0;
	dfs(farthestNode, 0);
	cout << diameter;
	return (0);
}