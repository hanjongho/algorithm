// 올바른 괄호

#include <string>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> s1;
    int i = 0;
    
    while(s[i])
    {
        if (s[i] == '(')
            s1.push('(');
        else if(s[i] == ')')
        {
            if (s1.empty())
            {
                answer = false;
                break;
            }
            else if (s1.top() == '(')
                s1.pop();
        }
        i++;
    }
    if (!s1.empty())
        answer = false;
    return answer;
}