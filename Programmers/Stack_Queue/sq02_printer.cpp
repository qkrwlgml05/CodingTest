#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int get_maxval (vector<int> input){
    int max = input[0];
    for (int i = 1; i < input.size(); i++){
        if (max < input[i])
            max = input[i];
    }
    return max;
}

int solution(vector<int> priorities, int location) {
    int answer = 0, index = location;
    vector<int> reprior;
    
    for (int i = 0; i < priorities.size(); i++){
        reprior.push_back(priorities[i]);
    }
    
    int max = get_maxval (reprior);
    
    while (reprior.size() != 0){
        if (reprior[0] < max){
            cout << "location : " << index << "\t" << "reprior[0]: " << reprior[0] << "\n";
            reprior.push_back(reprior[0]);
            reprior.erase(reprior.begin());
            if (index == 0){
                cout << reprior.size() << "\n";
                index = reprior.size()-1;
                continue;
            }
            index-=1;
        } else if (reprior[0] == max){
            answer += 1;
            if (index == 0)
                break;
            reprior.erase(reprior.begin());
            index -= 1;
            max = get_maxval (reprior);
        }
    }
    
    return answer;
}
