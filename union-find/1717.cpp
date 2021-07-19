#include <iostream>
using namespace std;

int parent[1000001], n, m, num, a, b;

int findParent(int i)
{ 
    if (parent[i] == i) 
        return i; 
    return parent[i] = findParent(parent[i]); 
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i <= n; i++)
        parent[i] = i; 

    for (int i = 0; i < m; i++)
    {
        cin >> num >> a >> b;
        if (num == 0)
		{
            a = findParent(a);
            b = findParent(b);
			if (a < b)
				parent[b] = a;
			else
				parent[a] = b;
		}
        else 
        {
            if (findParent(a) == findParent(b)) 
                cout << "YES\n";
            else 
                cout << "NO\n";
        } 
    } 
} 