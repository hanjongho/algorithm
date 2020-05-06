#include <iostream>
using namespace std;

int N, M, K;
int arr[1000001];
long long tree[4000004];

long long init(int start, int end, int node){
    if(start == end)
        return tree[node] = arr[start];
    
    int mid = (start + end) / 2;
    
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

long long sum(int start, int end, int node, int left, int right){
    if(left > end || right < start)
        return 0;
    
    if(left <= start && end <= right)
        return tree[node];
    
    int mid = (start + end) / 2;
    
    return sum(start, mid, node * 2, left, right) + sum(mid+1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, int change){
    if(index < start || index > end)
        return;
    
    tree[node] += change;
    if(start == end)
        return;
    
    int mid = (start + end) / 2;
    update(start, mid, node * 2, index, change);
    update(mid+1, end, node * 2 + 1, index, change);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
   
    cin >> N >> M >> K;
    
    for(int i=0; i<N; i++)
        cin >> arr[i];
    
    init(0, N-1, 1);

    for(int i=0; i<M+K; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1){ // 1이면 변경
            update(0, N-1, 1, b-1, c-arr[b-1]);
            arr[b-1] = c;
        }
        else if(a == 2) // 2이면 출력
            cout << sum(0, N-1, 1, b-1, c-1) << "\n";
    }
    
    return 0;
}
