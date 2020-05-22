#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void init(vector<int> &array, vector<int> &tree, int node, int start, int end){
    if (start == end)
        tree[node] = start;
    else{
        int mid = (start + end) / 2;
        init(array, tree, node * 2, start, mid);
        init(array, tree, node * 2 + 1, mid + 1, end);
        if (array[tree[node * 2]] < array[tree[node * 2 + 1]])
            tree[node] = tree[node * 2];
        else
            tree[node] = tree[node * 2 + 1];
    }
}

int query(vector<int> &array, vector<int> &tree, int node, int start, int end, int left, int right){
    if (end < left || start > right)
        return -1;
    else if (left <= start && end <= right)
        return tree[node];
    
    int mid = (start + end) / 2;
    int leftQuery  = query(array, tree, node * 2,      start,     mid, left, right);
    int rightQuery = query(array, tree, node * 2 + 1,  mid + 1,   end, left, right);
    
    if(leftQuery == -1)
        return rightQuery;
    else if (rightQuery == -1 || array[leftQuery] < array[rightQuery])
        return leftQuery;
    else
        return rightQuery;
}

long long getMaxArea(vector<int> &array, vector<int> &tree, int start, int end){
    int N = array.size() - 1;
    int idx = query(array, tree, 1, 1, N, start, end);
    long long area = (end - start + 1) * (long long)array[idx];
    
    //왼쪽에 남은 막대가 존재하는가
    if (start < idx){
        long long temp = getMaxArea(array, tree, start, idx - 1);
        area = max(area, temp);
    }

    //오른쪽에 남은 막대가 존재하는가
    if (idx < end){
        long long temp = getMaxArea(array, tree, idx + 1, end);
        area = max(area, temp);
    }
    return area;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    while (1){
        int N;
        cin >> N;
        if (N == 0)
            break;
        
        vector<int> arr(N+1), tree(4*N);
        for (int i = 1; i <= N; i++)
            cin >> arr[i];
        init(arr, tree, 1, 1, N);
        cout << getMaxArea(arr, tree, 1, N) << "\n";
    }
    return 0;
}
