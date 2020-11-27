// 다리를 지나는 트럭

#include <string>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, bridge_weight = 0;
    vector<pair<int, int>> bridge;
    
    while (1)
    {
        answer++;
        if (!truck_weights.empty() && bridge_weight + truck_weights[0] <= weight)
        {
            bridge.push_back({truck_weights[0], bridge_length});
            bridge_weight += truck_weights[0];
            truck_weights.erase(truck_weights.begin());
        }
        for (int i = 0; i < bridge.size(); i++)
            bridge[i].second--;
        if (bridge[0].second == 0)
        {
            bridge_weight -= bridge[0].first;
            bridge.erase(bridge.begin());
        }
        if (!truck_weights.size() && bridge.empty())
            break ;
    }
    answer++;
    return answer;
}