//
//  main.c
//  2579
//
//  Created by 한종호 on 06/07/2019.
//  Copyright © 2019 한종호. All rights reserved.
//

#include <iostream>
using namespace std;
int arr[1001], dp[1001], N, temp=0;
int main(){
    cin >> N;
    for(int i=1; i<=N; i++)
        cin >> arr[i];
    
    for(int i = 1; i<=N; i++){
        dp[i]++;
        for(int j=1; j<i; j++)
            if(arr[j] < arr[i])
                temp = max(temp, dp[j]);
        dp[i] += temp;
        temp = 0;
    }
    
    for(int i=1; i<=N; i++)
        temp = max(temp, dp[i]);
    cout << temp;
    return 0;
}
