#include <iostream>
#include <stack>
using namespace std;

int n;

int main(){
    while(1){
        cin >> n;
        if(!n)
            break;
        
        stack<int> s;
        int h[100001];
        long long area = 0, height, width;
        
        for (int i = 0; i < n; i++)
            cin >> h[i];
 
        for(int i = 0; i < n; i++){
            while(!s.empty() && h[s.top()] > h[i]){
                height = h[s.top()];
                width = i;
                s.pop();
                if(!s.empty())
                    width = i - s.top() - 1;
                area = max(area, width * height);
                cout << area << "\n";
            }
            s.push(i);
        }
        
        while(!s.empty()){
            height = h[s.top()];
            width = n;
            s.pop();
            if(!s.empty())
                width = n - s.top() - 1;
            area = max(area, width *height);
        }
        cout << area << "\n";
    }
    
    return 0;
}
