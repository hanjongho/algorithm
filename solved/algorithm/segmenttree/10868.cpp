#include <iostream>
using namespace std;

#define INF 1000000001

int N, M;
int arr[100001], minTree[400004];

int makeMinTree(int node, int start, int end){
    if(start == end)
        return minTree[node] = arr[start];
    
    int mid = (start + end) / 2;
    
    return minTree[node] = min(makeMinTree(node * 2, start, mid), makeMinTree(node * 2 + 1, mid + 1, end));
}

int returnMin(int node, int left, int right, int start, int end) {
    if(right < start || end < left)
        return INF; //구간밖
    
    if(start <= left && right <= end)
        return minTree[node];

    int mid = (left + right) / 2;

    return min(returnMin(node * 2, left, mid, start, end), returnMin(node * 2 + 1, mid + 1, right, start, end));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    makeMinTree(1, 1, N);

    while(M--) {
        int a, b;
        cin >> a >> b;
        cout << returnMin(1, 1, N, a, b) << "\n";
    }
    
    return 0;
}

