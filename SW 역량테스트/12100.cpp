#include <iostream>
#include <queue>
using namespace std;
int N, map[21][21], map_copy[21][21];
int max_ = -1;

// 1 2 3 4 -> 시계방향.

void move(int dir) {
    int t;
    queue<int> q;
    
    if (dir == 0) { //위로 다 몰기
        for (int j = 1; j <= N; j++) {
            for (int i = 1; i <= N; i++) {
                if (map[i][j] > max_)
                    max_ = map[i][j];
                if (map[i][j] != 0) {
                    q.push(map[i][j]);
                    map[i][j] = 0;
                }
            }
            t = 1;
            while (!q.empty()) {
                map[t++][j] = q.front();
                q.pop();
            }
        }
    }
    else if (dir == 1) { // 오른쪽으로 다 몰기
        for (int i = 1; i <= N; i++) {
            for (int j = N; j >= 1; j--) {
                if (map[i][j] > max_)
                    max_ = map[i][j];
                if (map[i][j] != 0) {
                    q.push(map[i][j]);
                    map[i][j] = 0;
                }
            }
            t = N;
            while (!q.empty()) {
                map[i][t--] = q.front();
                q.pop();
            }
        }
    }
    
    else if (dir == 2) { //아래로 다 몰기
        for (int j = 1; j <= N; j++) {
            for (int i = N; i >= 1; i--) {
                if (map[i][j] > max_)
                    max_ = map[i][j];
                if (map[i][j] != 0) {
                    q.push(map[i][j]);
                    map[i][j] = 0;
                }
            }
            t = N;
            while (!q.empty()) {
                map[t--][j] = q.front();
                q.pop();
            }
        }
    }
    else if (dir == 3) { // 왼쪽으로 다몰기
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (map[i][j] > max_)
                    max_ = map[i][j];
                if (map[i][j] != 0) {
                    q.push(map[i][j]);
                    map[i][j] = 0;
                }
            }
            t = 1;
            while (!q.empty()) {
                map[i][t++] = q.front();
                q.pop();
            }
        }
    }
}

void add(int dir){
    
    if (dir == 0) {
        for (int j = 1; j <= N; j++) {
            for (int i = 1; i <= N-1; i++) {
                if (map[i][j] != 0 && map[i + 1][j] == map[i][j]) {
                    map[i][j] *= 2;
                    map[i + 1][j] = 0;
                    i++;
                }
            }
        }
    }
    
    else if (dir == 1) {
        for (int i = 1; i <= N; i++) {
            for (int j = N; j > 1; j--) {
                if (map[i][j] != 0 && map[i][j - 1] == map[i][j]) {
                    map[i][j] *= 2;
                    map[i][j - 1] = 0;
                    j--;
                }
            }
        }
    }
    
    else if (dir == 2) {
        for (int j = 1; j <= N; j++) {
            for (int i = N; i > 1; i--) {
                if (map[i][j] != 0 && map[i - 1][j] == map[i][j]) {
                    map[i][j] *= 2;
                    map[i - 1][j] = 0;
                    i--;
                }
            }
        }
    }
    
    else if (dir == 3) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N - 1; j++) {
                if (map[i][j] != 0 && map[i][j + 1] == map[i][j]) {
                    map[i][j] *= 2;
                    map[i][j + 1] = 0;
                    j++;
                }
            }
        }
    }
}

void dfs(int depth, int dir) {
    
    if (depth == 5) {
        return;
    }
    
    int map_copy[21][21];
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            map_copy[i][j] = map[i][j];
        }
    }
    move(dir); // 값 몰기 (1/2)
    add(dir);  //1. 같은 숫자끼리 더해주는 작업
    move(dir); // 사이에 한번 뜰 수도 있으니 다시 한번 몰아주는 작업 (2/2) ex 4 4 8
    
    for (int i = 0; i < 4; i++) { // 재귀
        dfs(depth + 1, i);
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            map[i][j] = map_copy[i][j];
        }
    }
}

int main() {
    
    scanf("%d", &N);
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    
    for (int dir = 0; dir < 4; dir++) {
        
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                map_copy[i][j] = map[i][j];
            }
        }
        
        dfs(0, dir);
        
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                map[i][j] = map_copy[i][j];
            }
        }
    }
    
    printf("%d\n", max_);
    return 0;
}
