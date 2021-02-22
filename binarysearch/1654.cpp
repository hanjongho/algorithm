#include <iostream>
using namespace std;

int K, N, total, cm;
long long a[10000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int max;
    cin >> K >> N;
    for (int i=0; i<K; i++)
    {
        cin >> a[i];
        if (a[i] > max)
            max = a[i];
    }
    
    long long left = 1, right = max, mid;
    
    while(right >= left)
    {
        total = 0;
        mid = (right + left) / 2;
        for (int i=0; i<K; i++)
            if (a[i] >= mid)
                total += (a[i]/mid);
        
        if (total >= N)
        {
            if (cm < mid)
                cm = mid;
            left = mid + 1;
        }
        else
            right = mid -1;
    }
    cout << cm;
    return (0);
}