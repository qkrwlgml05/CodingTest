#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
vector<int> minmax (vector<int> answer){
    int min = 0, max = 0;
    for (int i = 0; i < answer.size(); i++){
        min = min>answer[i]||i==0?answer[i]:min;
        max = max<answer[i]||i==0?answer[i]:max;
    }
    return vector<int>{max,min};
}
vector<int> solution(vector<string> operations) {
    vector<int> answer{};
    for (int i = 0; i < operations.size(); i++){
        if (operations[i].compare("D 1")==0 && answer.size()>0){ // Delete max
            sort(answer.begin(), answer.end(), less<int>());
            answer.pop_back();
        }else if (operations[i].compare("D -1")==0 && answer.size()>0){ // Delete min
            sort(answer.begin(), answer.end(), greater<int>());
            answer.pop_back();
        }else if (operations[i][0] == 'I') // Insert N
            answer.push_back(stoi(operations[i].substr(2)));
    }
    if (answer.size()==0)
        return vector<int>{0,0};
    
    return minmax(answer);
}
