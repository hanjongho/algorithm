/// 가장 큰 수

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string s1, string s2)
{
    return s1 + s2 > s2 + s1 ? true : false;
}

string solution(vector<int> numbers) {
    vector<string> number(numbers.size());
    string answer = "";
    for (int i = 0; i < numbers.size(); i++)
        number[i] = to_string(numbers[i]);
    sort(number.begin(), number.end(), compare);
    
    for (int i = 0; i < number.size(); i++)
        answer += number[i];
    if (answer[0] == '0')
        answer = '0';
    return answer;
}