#include <iostream>
#include <vector>
using namespace std;

void fuc(vector<int> array){
    int t = array.size();
    while(t--){
        array[t] = 5;
    }
}

int main(){
    vector<int> arr = {1,2,3,4};
    arr.push_back(5);
    fuc(arr);
    for(int i=0; i<5; i++)
        cout << arr[i];
    return 0;
}
