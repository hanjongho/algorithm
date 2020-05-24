//
//  3980.cpp
//  solved
//
//  Created by 한종호 on 24/05/2020.
//  Copyright © 2020 hanjongho. All rights reserved.
//

#include <iostream>
using namespace std;

int C;
int playAbility[12][12];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> C;
    while(C--){
        for(int i=1; i<=11; i++)
            for(int j=1; j<=11; j++)
                cin >> playAbility[i][j];
        
        
    }
    
    return 0;
}
