#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = bridge_length;
    int i = 0;
    vector<int> bridge(bridge_length, 0);
    int weightsum = 0;
    
    while (i < truck_weights.size()){
        if (weightsum-bridge[0] + truck_weights[i] <= weight){
            weightsum -= bridge[0];
            weightsum += truck_weights[i];
            
            bridge.erase(bridge.begin());
            bridge.push_back(truck_weights[i]);
            
            i++;
        }
        else{
            weightsum -= bridge[0];
            bridge.erase(bridge.begin());
            bridge.push_back(0);
        }
        answer+=1;
    }
    
    return answer;
}
