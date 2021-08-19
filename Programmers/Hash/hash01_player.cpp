#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare (string a, string b){
    return a.compare(b) < 0;
}

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end(), compare);
    sort(completion.begin(), completion.end(), compare);
    int i = 0;
    for (i = 0; i < completion.size(); i++){
        if (participant[i].compare(completion[i])!=0){
            answer.assign(participant[i]);
            break;
        }
    }
    if (i == completion.size()){
        answer.assign(participant[i]);
    }
    
    return answer;
}
