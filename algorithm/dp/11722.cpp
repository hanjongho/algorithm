#include <iostream>
using namespace std;

int arr[1001], cnt[1001];
int number, temp = 0;

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> number;
    
    for(int i=number; i>=1; i--)
        cin >> arr[i];
    
    for(int i = 1; i<=number; i++){
        cnt[i]++;
        for(int j=1; j<i; j++)
            if(arr[j] < arr[i])
                temp = max(temp, cnt[j]);
        cnt[i] += temp;
        temp = 0;
    }
    
    temp = -1;
    for(int i=number; i>=1; i--){
        cout << cnt[i] << " ";
        temp = max(temp, cnt[i]);
    }
    // cout << temp;
    
    return 0;
}
