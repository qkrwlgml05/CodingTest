#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(int a, int b){
    return a < b;
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (int i = 0; i < commands.size(); i++){
        vector<int> temp(array.begin()+commands[i][0]-1, array.begin()+commands[i][1]);
        sort(temp.begin(), temp.end(), compare);
        answer.push_back(temp[commands[i][2]-1]);
    }
    return answer;
}
