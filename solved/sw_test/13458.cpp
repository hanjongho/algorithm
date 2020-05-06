#include <iostream>
using namespace std;

int N, B, C;
long long sum;
int arr[1000001];

int main()
{
    cin >> N;
    for(int i=1; i<=N; i++)
        cin >> arr[i];
    
    cin >> B >> C;
    
    sum = N;
    
    for(int i=1; i<=N; i++){
        arr[i] -= B;
        
        if(arr[i] > 0){
            if(arr[i] % C != 0)
                sum += (arr[i] / C + 1);
            else if(arr[i] % C == 0)
                sum += arr[i] / C;
        }
        
    }
    cout << sum << endl;
    
    
    return 0;
}
