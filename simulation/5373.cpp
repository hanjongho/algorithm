#include <iostream>
using namespace std;

int cube[7][4][4];
int t, n;
char side, dir;

void print(){
    for(int i=1; i<=3; i++){
           for(int j=1; j<=3; j++){
               if(cube[1][i][j] == 1)
                   printf("w");
               else if(cube[1][i][j] == 2)
                   printf("y");
               else if(cube[1][i][j] == 3)
                   printf("r");
               else if(cube[1][i][j] == 4)
                   printf("o");
               else if(cube[1][i][j] == 5)
                   printf("g");
               else if(cube[1][i][j] == 6)
                   printf("b");
           }
           printf("\n");
       }
}
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=1; i<=6; i++)
            for(int j=1; j<=3; j++)
                for(int k=1; k<=3; k++)
                    cube[i][j][k] = i;
            
        for(int i=0; i<n; i++){
            cin >> side >> dir;
            int t1, t2, t3;
            
            if(side == 'U'){
                t1 = cube[3][1][1];
                t2 = cube[3][1][2];
                t3 = cube[3][1][3];
                if(dir == '+'){
                    cube[3][1][1] = cube[6][1][1];
                    cube[3][1][2] = cube[6][1][2];
                    cube[3][1][3] = cube[6][1][3];
                    
                    cube[6][1][1] = cube[4][1][1];
                    cube[6][1][2] = cube[4][1][2];
                    cube[6][1][3] = cube[4][1][3];
                    
                    cube[4][1][1] = cube[5][1][1];
                    cube[4][1][2] = cube[5][1][2];
                    cube[4][1][3] = cube[5][1][3];
                    
                    cube[5][1][1] = t1;
                    cube[5][1][2] = t2;
                    cube[5][1][3] = t3;
                    
                    int temp = cube[1][1][1];
                    cube[1][1][1] = cube[1][3][1];
                    cube[1][3][1] = cube[1][3][3];
                    cube[1][3][3] = cube[1][1][3];
                    cube[1][1][3] = temp;
                    
                    temp = cube[1][1][2];
                    cube[1][1][2] = cube[1][2][1];
                    cube[1][2][1] = cube[1][3][2];
                    cube[1][3][2] = cube[1][2][3];
                    cube[1][2][3] = temp;
                }
                else if(dir == '-'){
                    cube[3][1][1] = cube[5][1][1];
                    cube[3][1][2] = cube[5][1][2];
                    cube[3][1][3] = cube[5][1][3];
                    
                    cube[5][1][1] = cube[4][1][1];
                    cube[5][1][2] = cube[4][1][2];
                    cube[5][1][3] = cube[4][1][3];
                    
                    cube[4][1][1] = cube[6][1][1];
                    cube[4][1][2] = cube[6][1][2];
                    cube[4][1][3] = cube[6][1][3];
                    
                    cube[6][1][1] = t1;
                    cube[6][1][2] = t2;
                    cube[6][1][3] = t3;
                    
                    int temp = cube[1][1][1];
                    cube[1][1][1] = cube[1][1][3];
                    cube[1][1][3] = cube[1][3][3];
                    cube[1][3][3] = cube[1][3][1];
                    cube[1][3][1] = temp;
                    
                    temp = cube[1][1][2];
                    cube[1][1][2] = cube[1][2][3];
                    cube[1][2][3] = cube[1][3][2];
                    cube[1][3][2] = cube[1][2][1];
                    cube[1][2][1] = temp;
                }
            }
            
            else if(side == 'D'){
                t1 = cube[3][3][1];
                t2 = cube[3][3][2];
                t3 = cube[3][3][3];
                if(dir == '+'){
                    cube[3][3][1] = cube[5][3][1];
                    cube[3][3][2] = cube[5][3][2];
                    cube[3][3][3] = cube[5][3][3];
                    
                    cube[5][3][1] = cube[4][3][1];
                    cube[5][3][2] = cube[4][3][2];
                    cube[5][3][3] = cube[4][3][3];
                    
                    cube[4][3][1] = cube[6][3][1];
                    cube[4][3][2] = cube[6][3][2];
                    cube[4][3][3] = cube[6][3][3];
                    
                    cube[6][3][1] = t1;
                    cube[6][3][2] = t2;
                    cube[6][3][3] = t3;
                    
                    int temp = cube[2][1][1];
                    cube[2][1][1] = cube[2][3][1];
                    cube[2][3][1] = cube[2][3][3];
                    cube[2][3][3] = cube[2][1][3];
                    cube[2][1][3] = temp;
                    
                    temp = cube[2][1][2];
                    cube[2][1][2] = cube[2][2][1];
                    cube[2][2][1] = cube[2][3][2];
                    cube[2][3][2] = cube[2][2][3];
                    cube[2][2][3] = temp;
                }
                else if(dir == '-'){
                    cube[3][3][1] = cube[6][3][1];
                    cube[3][3][2] = cube[6][3][2];
                    cube[3][3][3] = cube[6][3][3];
                    
                    cube[6][3][1] = cube[4][3][1];
                    cube[6][3][2] = cube[4][3][2];
                    cube[6][3][3] = cube[4][3][3];
                    
                    cube[4][3][1] = cube[5][3][1];
                    cube[4][3][2] = cube[5][3][2];
                    cube[4][3][3] = cube[5][3][3];
                    
                    cube[5][3][1] = t1;
                    cube[5][3][2] = t2;
                    cube[5][3][3] = t3;
                    
                    int temp = cube[2][1][1];
                    cube[2][1][1] = cube[2][1][3];
                    cube[2][1][3] = cube[2][3][3];
                    cube[2][3][3] = cube[2][3][1];
                    cube[2][3][1] = temp;
                    
                    temp = cube[2][1][2];
                    cube[2][1][2] = cube[2][2][3];
                    cube[2][2][3] = cube[2][3][2];
                    cube[2][3][2] = cube[2][2][1];
                    cube[2][2][1] = temp;
                }
            }
            else if(side == 'F'){
                t1 = cube[1][3][1];
                t2 = cube[1][3][2];
                t3 = cube[1][3][3];
                if(dir == '+'){
                    cube[1][3][1] = cube[5][3][3];
                    cube[1][3][2] = cube[5][2][3];
                    cube[1][3][3] = cube[5][1][3];
                    
                    cube[5][3][3] = cube[2][1][3];
                    cube[5][2][3] = cube[2][1][2];
                    cube[5][1][3] = cube[2][1][1];
                    
                    cube[2][1][3] = cube[6][1][1];
                    cube[2][1][2] = cube[6][2][1];
                    cube[2][1][1] = cube[6][3][1];
                    
                    cube[6][1][1] = t1;
                    cube[6][2][1] = t2;
                    cube[6][3][1] = t3;
                    
                    int temp = cube[3][1][1];
                    cube[3][1][1] = cube[3][3][1];
                    cube[3][3][1] = cube[3][3][3];
                    cube[3][3][3] = cube[3][1][3];
                    cube[3][1][3] = temp;
                    
                    temp = cube[3][1][2];
                    cube[3][1][2] = cube[3][2][1];
                    cube[3][2][1] = cube[3][3][2];
                    cube[3][3][2] = cube[3][2][3];
                    cube[3][2][3] = temp;
                }
                else if(dir == '-'){
                    cube[1][3][1] = cube[6][1][1];
                    cube[1][3][2] = cube[6][2][1];
                    cube[1][3][3] = cube[6][3][1];
                    
                    cube[6][1][1] = cube[2][1][3];
                    cube[6][2][1] = cube[2][1][2];
                    cube[6][3][1] = cube[2][1][1];
                    
                    cube[2][1][3] = cube[5][3][3];
                    cube[2][1][2] = cube[5][2][3];
                    cube[2][1][1] = cube[5][1][3];
                    
                    cube[5][3][3] = t1;
                    cube[5][2][3] = t2;
                    cube[5][1][3] = t3;
                    
                    int temp = cube[3][1][1];
                    cube[3][1][1] = cube[3][1][3];
                    cube[3][1][3] = cube[3][3][3];
                    cube[3][3][3] = cube[3][3][1];
                    cube[3][3][1] = temp;
                    
                    temp = cube[3][1][2];
                    cube[3][1][2] = cube[3][2][3];
                    cube[3][2][3] = cube[3][3][2];
                    cube[3][3][2] = cube[3][2][1];
                    cube[3][2][1] = temp;
                }
            }
            else if(side == 'B'){
                t1 = cube[1][1][1];
                t2 = cube[1][1][2];
                t3 = cube[1][1][3];
                if(dir == '+'){
                    cube[1][1][1] = cube[6][1][3];
                    cube[1][1][2] = cube[6][2][3];
                    cube[1][1][3] = cube[6][3][3];
                    
                    cube[6][1][3] = cube[2][3][3];
                    cube[6][2][3] = cube[2][3][2];
                    cube[6][3][3] = cube[2][3][1];
                    
                    cube[2][3][3] = cube[5][3][1];
                    cube[2][3][2] = cube[5][2][1];
                    cube[2][3][1] = cube[5][1][1];
                    
                    cube[5][3][1] = t1;
                    cube[5][2][1] = t2;
                    cube[5][1][1] = t3;
                    
                    int temp = cube[4][1][1];
                    cube[4][1][1] = cube[4][3][1];
                    cube[4][3][1] = cube[4][3][3];
                    cube[4][3][3] = cube[4][1][3];
                    cube[4][1][3] = temp;
                    
                    temp = cube[4][1][2];
                    cube[4][1][2] = cube[4][2][1];
                    cube[4][2][1] = cube[4][3][2];
                    cube[4][3][2] = cube[4][2][3];
                    cube[4][2][3] = temp;
                }
                else if(dir == '-'){
                    cube[1][1][1] = cube[5][3][1];
                    cube[1][1][2] = cube[5][2][1];
                    cube[1][1][3] = cube[5][1][1];
                    
                    cube[5][3][1] = cube[2][3][3];
                    cube[5][2][1] = cube[2][3][2];
                    cube[5][1][1] = cube[2][3][1];
                    
                    cube[2][3][3] = cube[6][1][3];
                    cube[2][3][2] = cube[6][2][3];
                    cube[2][3][1] = cube[6][3][3];
                    
                    cube[6][1][3] = t1;
                    cube[6][2][3] = t2;
                    cube[6][3][3] = t3;

                    
                    int temp = cube[4][1][1];
                    cube[4][1][1] = cube[4][1][3];
                    cube[4][1][3] = cube[4][3][3];
                    cube[4][3][3] = cube[4][3][1];
                    cube[4][3][1] = temp;
                    
                    temp = cube[4][1][2];
                    cube[4][1][2] = cube[4][2][3];
                    cube[4][2][3] = cube[4][3][2];
                    cube[4][3][2] = cube[4][2][1];
                    cube[4][2][1] = temp;
                }
            }
            else if(side == 'L'){
                t1 = cube[1][1][1];
                t2 = cube[1][2][1];
                t3 = cube[1][3][1];
                if(dir == '+'){
                    cube[1][1][1] = cube[4][3][3];
                    cube[1][2][1] = cube[4][2][3];
                    cube[1][3][1] = cube[4][1][3];
                    
                    cube[4][3][3] = cube[2][1][1];
                    cube[4][2][3] = cube[2][2][1];
                    cube[4][1][3] = cube[2][3][1];
                    
                    cube[2][1][1] = cube[3][1][1];
                    cube[2][2][1] = cube[3][2][1];
                    cube[2][3][1] = cube[3][3][1];
                    
                    cube[3][1][1] = t1;
                    cube[3][2][1] = t2;
                    cube[3][3][1] = t3;
                    
                    int temp = cube[5][1][1];
                    cube[5][1][1] = cube[5][3][1];
                    cube[5][3][1] = cube[5][3][3];
                    cube[5][3][3] = cube[5][1][3];
                    cube[5][1][3] = temp;
                    
                    temp = cube[5][1][2];
                    cube[5][1][2] = cube[5][2][1];
                    cube[5][2][1] = cube[5][3][2];
                    cube[5][3][2] = cube[5][2][3];
                    cube[5][2][3] = temp;
                }
                else if(dir == '-'){
                    cube[1][1][1] = cube[3][1][1];
                    cube[1][2][1] = cube[3][2][1];
                    cube[1][3][1] = cube[3][3][1];
                    
                    cube[3][1][1] = cube[2][1][1];
                    cube[3][2][1] = cube[2][2][1];
                    cube[3][3][1] = cube[2][3][1];
                    
                    cube[2][1][1] = cube[4][3][3];
                    cube[2][2][1] = cube[4][2][3];
                    cube[2][3][1] = cube[4][1][3];
                    
                    cube[4][3][3] = t1;
                    cube[4][2][3] = t2;
                    cube[4][1][3] = t3;
                    
                    int temp = cube[5][1][1];
                    cube[5][1][1] = cube[5][1][3];
                    cube[5][1][3] = cube[5][3][3];
                    cube[5][3][3] = cube[5][3][1];
                    cube[5][3][1] = temp;
                    
                    temp = cube[5][1][2];
                    cube[5][1][2] = cube[5][2][3];
                    cube[5][2][3] = cube[5][3][2];
                    cube[5][3][2] = cube[5][2][1];
                    cube[5][2][1] = temp;
                }
            }
            else if(side == 'R'){
                t1 = cube[1][1][3];
                t2 = cube[1][2][3];
                t3 = cube[1][3][3];
                if(dir == '+'){
                    cube[1][1][3] = cube[3][1][3];
                    cube[1][2][3] = cube[3][2][3];
                    cube[1][3][3] = cube[3][3][3];
                    
                    cube[3][1][3] = cube[2][1][3];
                    cube[3][2][3] = cube[2][2][3];
                    cube[3][3][3] = cube[2][3][3];
                    
                    cube[2][1][3] = cube[4][3][1];
                    cube[2][2][3] = cube[4][2][1];
                    cube[2][3][3] = cube[4][1][1];
                    
                    cube[4][3][1] = t1;
                    cube[4][2][1] = t2;
                    cube[4][1][1] = t3;
                    
                    int temp = cube[6][1][1];
                    cube[6][1][1] = cube[6][3][1];
                    cube[6][3][1] = cube[6][3][3];
                    cube[6][3][3] = cube[6][1][3];
                    cube[6][1][3] = temp;
                    
                    temp = cube[6][1][2];
                    cube[6][1][2] = cube[6][2][1];
                    cube[6][2][1] = cube[6][3][2];
                    cube[6][3][2] = cube[6][2][3];
                    cube[6][2][3] = temp;
                }
                else if(dir == '-'){
                    cube[1][1][3] = cube[4][3][1];
                    cube[1][2][3] = cube[4][2][1];
                    cube[1][3][3] = cube[4][1][1];
                    
                    cube[4][3][1] = cube[2][1][3];
                    cube[4][2][1] = cube[2][2][3];
                    cube[4][1][1] = cube[2][3][3];
                    
                    cube[2][1][3] = cube[3][1][3];
                    cube[2][2][3] = cube[3][2][3];
                    cube[2][3][3] = cube[3][3][3];
                    
                    cube[3][1][3] = t1;
                    cube[3][2][3] = t2;
                    cube[3][3][3] = t3;
                    
                    int temp = cube[6][1][1];
                    cube[6][1][1] = cube[6][1][3];
                    cube[6][1][3] = cube[6][3][3];
                    cube[6][3][3] = cube[6][3][1];
                    cube[6][3][1] = temp;
                    
                    temp = cube[6][1][2];
                    cube[6][1][2] = cube[6][2][3];
                    cube[6][2][3] = cube[6][3][2];
                    cube[6][3][2] = cube[6][2][1];
                    cube[6][2][1] = temp;
                }
            }
        }
        print();
    }
    return 0;
}
