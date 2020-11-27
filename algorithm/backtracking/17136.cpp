#include <iostream>
using namespace std;
 
int map[11][11], cp[6], result = 2e9;
// cp[i] : i 크기의 색종이의 수
 
void coloring(int y, int x, int size, int n){
    for (int i = y; i < y + size; i++)
        for (int j = x; j < x + size; j++)
            map[i][j] = n;
}

bool isStick(int y, int x, int c){
    for (int i = y; i < y + c; i++)
        for (int j = x; j < x + c; j++)
            if (!map[i][j])
                return false;
    return true;
}
 
void backtracking(int total, int y, int x){
    // total이 이미 result보다 클 경우 진행할 필요 없음.
    if (total > result)
        return;
 
    // x가 10 이상일 경우 다음 y(행)로 넘어간다.
    if (x >= 10){
        x = 0;
        ++y;
    }
 
    // y가 10 이상인 경우는 끝난 경우이므로, result 갱신한다.
    if (y >= 10){
        result = min(result, total);
        return;
    }
 
    // 스티커를 못붙이는자리라면 -> 애초에 0인 자리
    if (!map[y][x]){
        backtracking(total, y, x + 1);
        return;
    }
 
 
    for (int size = 1; size <= 5; size++)
        if (isStick(y, x, size) && cp[size] < 5){
            // 해당자리 1~5 크기 스티커 붙인 경우
            coloring(y, x, size, 0);
            ++cp[size];
            backtracking(total + 1, y, x + 1);
            // 원래대로 돌리기
            coloring(y, x, size, 1);
            --cp[size];
        }
}
 
int main(void){
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            cin >> map[i][j];
    
    backtracking(0, 0, 0);
    
    if(result == 2e9)
        cout << "-1";
    else
        cout << result;
 
    return 0;
}