// 전화번호 목록

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string s1, string s2)
{
    return s1.size() < s2.size();
}

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end(), compare);
    for (int i = 0; i < phone_book.size(); i++)
        for (int j = i + 1; j < phone_book.size(); j++)
            if (phone_book[i] == phone_book[j].substr(0, phone_book[i].size()))
                return false; 
    return true;
}