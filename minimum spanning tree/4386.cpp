#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
 
int n;
int parent[101];
double x, y;
vector<pair<double, double>> stars;
vector<pair<double, pair<int, int>>> v;
double answer = 0;
 
int findParent(int x)
{
    if (x == parent[x])
        return x;
        
    return parent[x] = findParent(parent[x]);
}
 
double cal(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout.precision(3);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        stars.push_back({x, y});
    }
 
    for (int i = 0; i < stars.size(); i++)
        for (int j = i + 1; j < stars.size(); j++)
            v.push_back({cal(stars[i].first, stars[i].second, stars[j].first, stars[j].second), {i, j}});
 
    for (int i = 0; i < n; i++)
        parent[i] = i;
 
    sort(v.begin(), v.end());
 
    for (int i = 0; i < v.size(); i++)
    {
        int x = v[i].second.first;
        int y = v[i].second.second;
        double cost = v[i].first;
 
        int a = findParent(x);
        int b = findParent(y);
 
        if (a != b)
        {
            if (a < b)
                parent[b] = findParent(a);
            else
                parent[a] = findParent(b);
            answer += cost;
        }
    }
 
    cout << answer << "\n";

    return (0);
}