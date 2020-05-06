
 #include <iostream>
#include <algorithm>

using namespace std;

int N, start_, end_;
pair<int, int> pointInformation[1000001];


int main(){
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> start_ >> end_;
        pointInformation[i].first = start_;
        pointInformation[i].second = end_;
    }
    
    sort(pointInformation, pointInformation+ N);
    
    for(int i=1; i<=N; i++){
        cout << pointInformation[i].first << " " << pointInformation[i].second << "\n";
    }
    
    
    
    return 0;
}
