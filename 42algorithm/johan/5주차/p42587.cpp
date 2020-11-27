// 프린터

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int save = priorities[location];
    int pop;
    while (!priorities.empty())
    {
        int flag = 0;
        pop = priorities[0];
        priorities.erase(priorities.begin());
        for (int i = 0; i < priorities.size(); i++)
        {
            if (priorities[i] > pop)
            {
                priorities.push_back(pop);
                flag = 1;
                break ;
            }
        }
        if (!flag)
        {
            answer++;
            if (save == pop && !location)
                break ;
        }
        if (location)
            location--;
        else
            location += priorities.size() - 1;
    }
    return answer;
}