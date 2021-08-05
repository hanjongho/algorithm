#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int parent[100001], dist[100001], visited[100001];
queue<int> q;

bool comp(pair<int, pair<int,int> > p1, pair<int, pair<int,int> > p2)
{
	return p1.first > p2.first;
}

int findParent(int x)
{
	if (parent[x] == x)
		return x;
	return (parent[x] = findParent(parent[x]));
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M, s, e;
	vector<pair<int, pair<int,int> > > v;
	vector<pair<int, int> > graph[100001];

	cin >> N >> M >> s >> e;
	for (int i = 0; i < M; i++)
	{
		int h1, h2, k;
		cin >> h1 >> h2 >> k;
		v.push_back({k, {h1, h2}});
	}

	for (int i = 1; i <= N; i++)
		parent[i] = i;

	sort(v.begin(), v.end(), comp);

	int connected = 0;
	for (int i = 0; i < M; i++)
	{
		if (connected == N - 1)
			break ;
		
		int startParent = findParent(v[i].second.first);
		int endParent = findParent(v[i].second.second);

		if (startParent != endParent)
		{
			if (startParent < endParent)
				parent[endParent] = findParent(startParent);
			else
				parent[startParent] = findParent(endParent);
			graph[v[i].second.first].push_back({v[i].second.second, v[i].first});
			graph[v[i].second.second].push_back({v[i].second.first, v[i].first});
			connected++;
		}
	}

    for (int i = 1; i <= N; i++) 
		dist[i] = 987654321;
    
    q.push(s);
    visited[s] = 1;
    while (!q.empty())
	{
        int now = q.front();
        q.pop();
        
        for (int i = 0; i < graph[now].size(); i++)
		{
            int next = graph[now][i].first;
            int nextCost = graph[now][i].second;
            
            if (!visited[next])
			{
				visited[next] = 1;
				dist[next] = min(dist[now], nextCost);
				q.push(next);
			}
        }
    }
    
    if (dist[e] == 987654321) 
		cout << "0\n";
    else
		cout << dist[e] << "\n";
	
	return (0);
}