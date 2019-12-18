#include <iostream>
#include <queue>
using namespace std;

int apple[101][2];
int N, K, L, current_x = 1, current_y = 1, ax, ay, time_, btime=0, move_dir = 1, cnt=0;
// 1,2,3,4 시계방향
char dir;
bool flag = false, end = false;
char a[10001];

typedef struct node *nodeptr;
typedef struct node{
    int x, y;
    nodeptr link;
};

nodeptr head = NULL;

void print_(){
    nodeptr a = head;
    while( a->link != NULL){
        printf("%d,%d\n", a->x, a->y);
        a = a->link;
    }
}

void add_list(int x, int y){
    nodeptr add = (nodeptr)malloc(sizeof(node));
    add->x = x;
    add->y = y;
    add->link = head;
    head = add;
}
int main() {
    
    scanf("%d %d", &N, &K);
    for(int i=1; i<=K; i++){
        scanf("%d %d", &ax, &ay);
        apple[i][0] = ax;
        apple[i][1] = ay;
    }
    scanf("%d", &L);
    while(L--){
        scanf("%d %c", &time_, &dir);
        a[time_] = dir;
    }
    
    head = (nodeptr)malloc(sizeof(node));
    head->x = 1;
    head->y = 1;
    head->link = NULL;
    
    while(1){
        cnt++;
        bool apple_ = false, end = false;
        
        // 현재 가르키고 있는 방향에 따른 좌표 증가
        if( move_dir == 1)
            current_y += 1;
        else if(move_dir == 2)
            current_x += 1;
        else if(move_dir == 3)
            current_y -= 1;
        else if(move_dir == 4)
            current_x -= 1;
        
        // 게임 ending 조건 벽이거나 자기 자신과 맞닿은 경우
        
        nodeptr p = head;
        while (p != NULL) { // 끝까지 탐색하기
            if(current_x == p->x && current_y == p->y)
                end = true;
            p = p->link;
        }
        if( current_x < 1 || current_x > N || current_y < 1 || current_y > N || end == true){
            printf("%d",cnt);
            return 0;
        }
        
        add_list(current_x, current_y);
        
        for(int t = 1; t <= K; t++){
            if(apple[t][0] == current_x && apple[t][1] == current_y){
                apple[t][0] = apple[t][1] = 0;
                apple_  = true;
                break;
            }
        }
        
        // 다음좌표가 사과가 없으면 링크드리스트
        if( apple_ == false){
            nodeptr tp = head;
            while(tp->link->link != NULL){ // 마지막 놈 찾기.
                tp = tp->link;
            }
            free(tp->link);
            tp->link = NULL;
        }
        
        // 해당 초가 지났을때 방향전환이 있으면 전환
        if(a[cnt] == 'D'){
            if(move_dir == 4)
                move_dir = 1;
            else
                move_dir+=1;
        }
        else if(a[cnt] == 'L'){
            if(move_dir == 1)
                move_dir = 4;
            else
                move_dir-=1;
        }
        
        //printf("위치 (%d,%d), 지난 시간 %d초\n",current_x, current_y, cnt);
    }
}
