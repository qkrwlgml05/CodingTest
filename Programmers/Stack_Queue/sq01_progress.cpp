#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer, check;
    vector<int> time(progresses.size(), 0);
    int index = 0;
    
    for (int i = 0; i < progresses.size(); i++){
        time[i] = ceil((100.0-float(progresses[i]))/float(speeds[i]));
    }
    
    for (int i = 0; i < progresses.size(); i++){
        if (i == 0){
            check.push_back(time[i]);
            answer.push_back(1);
        } else if(time[i] <= check[check.size()-1]){
            answer[answer.size()-1]+=1;
        } else {
            check.push_back(time[i]);
            answer.push_back(1);
        }
        
    }
    return answer;
}
