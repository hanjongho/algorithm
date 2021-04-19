#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

vector<pair<int, int> > graph[10001];
int n, diameter = 0, farthestNode = 0, s, e, w;
int visited[10001];

void dfs(int node, int weight)
{
	if (visited[node])
		return ;
	visited[node] = 1;
	if (diameter < weight)
	{
		diameter = weight;
		farthestNode = node;
	}
	for (int i = 0; i < graph[node].size(); i++)
		dfs(graph[node][i].first, weight + graph[node][i].second);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> s >> e >> w;
		graph[s].push_back(make_pair(e, w));
		graph[e].push_back(make_pair(s, w));
	}
	dfs(1, 0);
	memset(visited, 0, sizeof(visited));
	diameter = 0;
	dfs(farthestNode, 0);
	cout << diameter;
	return (0);
}