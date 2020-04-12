#include <iostream>
#define swap(a,b,temp) temp=a; a=b; b=temp;
using namespace std;

int N, temp, value, score, result = -1;
int point[51][10], arr[10] = {0,4,1,2,3,5,6,7,8,9}, order[10], base[4];

void permutations(int *arr, int k, int m){ // k = 시작점
    
    if(k == m){ // arr[]의 값이 순서가 됨. 새로운 순열 채워짐
       
        for(int i=1; i<=9; i++)
            order[arr[i]] = i;
        
        score = value = 0;
        for(int i=1; i<=N; i++){ // 1개의 게임
            int outcount = base[1] = base[2] = base[3] = 0;
            
            while(outcount != 3){
                value = (value % 9) + 1;
                if(point[i][order[value]] == 0)
                    outcount++;
                else if(point[i][order[value]] == 1){
                    if(base[3]){
                        base[3] = 0;
                        score++;
                    }
                    if(base[2]){
                        base[2] = 0;
                        base[3] = 1;
                    }
                    if(base[1]){
                        base[1] = 0;
                        base[2] = 1;
                    }
                    base[1] = 1;
                }
                else if(point[i][order[value]] == 2){
                    if(base[3]){
                        base[3] = 0;
                        score++;
                    }
                    if(base[2]){
                        base[2] = 0;
                        score++;
                    }
                    if(base[1]){
                        base[1] = 0;
                        base[3] = 1;
                    }
                    base[2] = 1;
                }
                else if(point[i][order[value]] == 3){
                    if(base[3]){
                        base[3] = 0;
                        score++;
                    }
                    if(base[2]){
                        base[2] = 0;
                        score++;
                    }
                    if(base[1]){
                        base[1] = 0;
                        score++;
                    }
                    base[3] = 1;
                }
                else if(point[i][order[value]] == 4){
                    if(base[3]){
                        base[3] = 0;
                        score++;
                    }
                    if(base[2]){
                        base[2] = 0;
                        score++;
                    }
                    if(base[1]){
                        base[1] = 0;
                        score++;
                    }
                    score++;
                }
            }
        }
        if(score > result)
            result = score;
    }
    
    else{
        for(int i = k; i <= m; i++){
            swap(arr[k], arr[i], temp);
            permutations(arr, k+1, m);
            swap(arr[k], arr[i], temp);
        }
    }
}

int main(){
    cin >> N;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=9; j++)
            cin >> point[i][j];
    permutations(arr, 2, 9);
    printf("%d\n",result);
}
