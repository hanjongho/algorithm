#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    char stack[51];
    int len = 0, number, a = 0;
    
	cin >> number;
    for (int i = 0; i < number; i++)
    {
		cin >> stack;
        for (int i = 0; i < strlen(stack); i++)
        {
            if (stack[i] == '(')
                a++;
            else if (stack[i] == ')')
                a--;
            if (a < 0)
                break;
        }
        if (a == 0)
			cout << "YES\n";
        else
			cout << "NO\n";
        a = 0;
    }
    return (0);
}
