#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    string str[100];
    
    for (int i = 0; i < 100; i++)
    {
        getline(cin, str[i]);
        cout << str[i] << endl;;
    }
}
