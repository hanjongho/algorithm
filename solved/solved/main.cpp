//
//  3980.cpp
//  solved
//
//  Created by 한종호 on 24/05/2020.
//  Copyright © 2020 hanjongho. All rights reserved.
//

#include <iostream>
using namespace std;

int N;
int cost[17][17];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            cin >> cost[i][j];
    
    return 0;
}
