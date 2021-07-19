#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int> max_pq;
priority_queue<int, vector<int>, greater<int> > min_pq;
int n;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0 ; i < n; i++)
    {
        int a;
        cin >> a;
        if (min_pq.size() == max_pq.size())
            max_pq.push(a);
        else
            min_pq.push(a);
        if (!min_pq.empty() && !max_pq.empty() && min_pq.top() < max_pq.top())
        {
            int min_value = min_pq.top();
            int max_value = max_pq.top();
            min_pq.pop();
            max_pq.pop();
            max_pq.push(min_value);
            min_pq.push(max_value);
        }
        cout << max_pq.top() << "\n";
    }
}