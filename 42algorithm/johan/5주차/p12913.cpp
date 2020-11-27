// 땅따먹기

#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>> land)
{
    for (int i = 1; i < land.size(); i++)
    {
        land[i][0] += max(max(land[i - 1][1], land[i - 1][2]), land[i - 1][3]);
        land[i][1] += max(max(land[i - 1][0], land[i - 1][2]), land[i - 1][3]);
        land[i][2] += max(max(land[i - 1][0], land[i - 1][1]), land[i - 1][3]);
        land[i][3] += max(max(land[i - 1][0], land[i - 1][1]), land[i - 1][2]);
    }
    int a = max(land[land.size()-1][0], land[land.size()-1][1]);
    int b = max(land[land.size()-1][2], land[land.size()-1][3]);
    return max(a, b);
}