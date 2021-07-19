#include <iostream>
#include <vector>
#include <stack>
#define max 1000000000
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while (1)
    {   
        string buf;
        vector<string> command;
        stack<int> s;
        int N, V;
        while (1)
        {
            cin >> buf;
            if (buf == "QUIT")
                return (0);
            if (buf == "NUM")
            {
                string tmp;
                cin >> tmp;
                tmp = " " + tmp;
                buf += tmp;
            }
            if (buf == "END")
                break;
            command.push_back(buf);
        }
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> V;
            bool errorCheck = 0;
            s.push(V);
            for (int j = 0; j < command.size(); j++)
            {
                if (command[j].substr(0, 3) == "NUM")
                {
                    long num = stoi(command[j].substr(4, command[j].length()));
                    if (num > max)
                    {
                        errorCheck = 1;
                        break ;
                    }
                    s.push(num);
                }
                else if (command[j] == "POP")
                {
                    if (s.size() == 0)
                    {
                        errorCheck = 1;
                        break ;
                    }
                    s.pop();
                }
                else if (command[j] == "INV")
                {
                    if (s.size() == 0)
                    {
                        errorCheck = 1;
                        break ;
                    }
                    int tmp = s.top();
                    s.pop();
                    s.push(tmp * -1);
                }
                else if (command[j] == "DUP")
                {
                    if (s.size() == 0)
                    {
                        errorCheck = 1;
                        break ;
                    }
                    s.push(s.top());
                }
                else if (command[j] == "SWP")
                {
                    if (s.size() < 2)
                    {
                        errorCheck = 1;
                        break ;
                    }
                    int tmp1 = s.top();
                    s.pop();
                    int tmp2 = s.top();
                    s.pop();
                    s.push(tmp1);
                    s.push(tmp2);
                }
                else if (command[j] == "ADD")
                {
                    if (s.size() < 2)
                    {
                        errorCheck = 1;
                        break ;
                    }
                    int tmp1 = s.top();
                    s.pop();
                    int tmp2 = s.top();
                    s.pop();
                    int tmp = tmp1 + tmp2;
                    if (tmp < -max || tmp > max)
                    {
                        errorCheck = 1;
                        break ;
                    }
                    s.push(tmp);
                }
                else if (command[j] == "SUB")
                {
                    if (s.size() < 2)
                    {
                        errorCheck = 1;
                        break ;
                    }
                    int tmp1 = s.top();
                    s.pop();
                    int tmp2 = s.top();
                    s.pop();
                    int tmp = tmp2 - tmp1;
                    if (tmp < -max || tmp > max)
                    {
                        errorCheck = 1;
                        break ;
                    }
                    s.push(tmp);
                }
                else if (command[j] == "MUL")
                {
                    if (s.size() < 2)
                    {
                        errorCheck = 1;
                        break ;
                    }
                    long tmp1 = s.top();
                    s.pop();
                    long tmp2 = s.top();
                    s.pop();
                    long tmp = tmp1 * tmp2;
                    if (tmp < -max || tmp > max)
                    {
                        errorCheck = 1;
                        break ;
                    }
                    s.push(tmp);
                }
                else if (command[j] == "DIV")
                {
                    if (s.size() < 2)
                    {
                        errorCheck = 1;
                        break ;
                    }
                    int tmp1 = s.top();
                    s.pop();
                    int tmp2 = s.top();
                    s.pop();
                    if (tmp1 == 0)
                    {
                        errorCheck = 1;
                        break ;
                    }
                    int tmp, minus=0;
                    if ((tmp1 > 0 && tmp2 < 0) || (tmp1 < 0 && tmp2 > 0))
                        minus = 1;
                    tmp = abs(tmp2) / abs(tmp1);
                    if (minus == 1)
                        tmp *= -1;
                    s.push(tmp);
                }
                else if (command[j] == "MOD")
                {
                    if (s.size() < 2)
                    {
                        errorCheck = 1;
                        break ;
                    }
                    int tmp1 = s.top();
                    s.pop();
                    int tmp2 = s.top();
                    s.pop();
                    if (tmp1 == 0)
                    {
                        errorCheck = 1;
                        break ;
                    }
                    int tmp, minus = 0;
                    if (tmp2 < 0)
                        minus = 1;
                    tmp = abs(tmp2) % abs(tmp1);
                    if (minus == 1)
                        tmp *= -1;
                    s.push(tmp);
                }
            }
            if (s.size() != 1 || errorCheck == 1)
                cout << "ERROR\n";
            else
                cout << s.top() << "\n";
            while (s.size() > 0)
                s.pop();
        }
        cout << "\n";
        command.clear();
    }
    
    return (0);
}