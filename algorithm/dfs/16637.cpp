#include<iostream>
#define MAX 20
using namespace std;
 
int N, answer = -987564321;
int num[MAX];
char oper[MAX];
int calc(int a, char oper, int b){
    if (oper == '+')
        return a + b;
    else if (oper == '-')
        return a - b;
    else
        return a * b;
}
 
void dfs(int idx, int result){
    if (idx >= N/2){
        if(result > answer)
            answer = result;
        return;
    }
    dfs(idx + 1, calc(result, oper[idx], num[idx + 1]));
    if (idx + 1 < N/2) // 뒤에 값이 있을때
        dfs(idx + 2, calc(result, oper[idx], calc(num[idx + 1], oper[idx + 1], num[idx + 2])));
}

int main()
{
    cin >> N;
    for(int i=0; i<N; i++){
        if(i%2 == 0)
            cin >> num[i/2];
        else
            cin >> oper[i/2];
    }
    if (N == 1)
        cout << num[0];
    else if (N == 3)
        cout << calc(num[0], oper[0], num[1]);
    else{
        dfs(0, num[0]);
        cout << answer;
    }
    return 0;
}
