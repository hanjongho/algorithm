#include <iostream>
using namespace std;

int N, M; 
int arr[9], visited[9]; 

void dfs(int idx, int cnt) 
{ 
    if (cnt == M) 
    { 
        for (int i = 0; i < M; i++)
            cout << arr[i] << " ";
        cout << "\n"; 
        return ;
    }
    for (int i = idx; i <= N; i++)
        if (!visited[i]) 
        { 
            visited[i] = 1;
            arr[cnt] = i; 
            dfs(i + 1, cnt + 1); 
            visited[i] = 0;
        }
}

int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M; 

    dfs(1, 0); 
}

