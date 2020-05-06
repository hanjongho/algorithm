#include <iostream>
using namespace std;
int arr[51][51], arr_c[51][51], order[7][3], a[6] = { 1, 2, 3, 4, 5, 6};
int N, M, K, INF = 2e9;

int used[6]; // 현재 사용한 숫자를 표시
int p[6]; // 순열을 저장할 배열

void count(){
    int sum = 0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            sum += arr[i][j];
        }
        INF = min(INF, sum);
        sum = 0;
    }
}

void copy(){
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
            arr[i][j] = arr_c[i][j];
}

void move(int sx, int sy, int ex, int ey){
    if( ex-sx < 1 || ey-sy < 1)
        return;
    else{
        int temp = arr[sx][sy];
        for(int i=sx+1; i<=ex; i++)
            arr[i-1][sy] = arr[i][sy];
        for(int j=sy+1; j<=ey; j++)
            arr[ex][j-1] = arr[ex][j];
        for(int i=ex-1; i>=sx; i--)
            arr[i+1][ey] = arr[i][ey];
        for(int j=ey-1; j>=sy; j--)
            arr[sx][j+1] = arr[sx][j];
        arr[sx][sy+1] = temp;
        move(sx+1, sy+1, ex-1, ey-1);
    }
}
void permutation(int n, int k){
    if(k == n){
        for(int i=0; i<n; i++){
            move(order[p[i]][0] - order[p[i]][2], order[p[i]][1] - order[p[i]][2],
                 order[p[i]][0] + order[p[i]][2], order[p[i]][1] + order[p[i]][2]);
        }
        count();
        copy();
    }
    else{
        for(int i = 0; i < n; i++){
            if (used[i] == 0){
                p[k] = a[i];
                used[i] = 1;
                permutation(n, k + 1);
                used[i] = 0;
            }
        }
    }
}

int main(){
    cin >> N >> M >> K;
    for(int i=1; i<=N; ++i)
        for(int j=1; j<=M; ++j){
            cin >> arr[i][j];
            arr_c[i][j] = arr[i][j];
        }
    
    for(int i=1; i<=K; i++)
        cin >> order[i][0] >> order[i][1] >> order[i][2];
    
    permutation(K, 0);
    
    cout << INF;
    return 0;
}
