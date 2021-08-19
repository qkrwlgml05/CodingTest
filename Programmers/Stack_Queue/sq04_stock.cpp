#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for (int i = 0; i < prices.size(); i++){
        answer.push_back(prices.size()-i-1);
        for (int j = i+1; j < prices.size(); j++){
            if (prices[i] > prices[j]){
                answer[i] = j-i;
                break;
            }
        }
    }
    return answer;
}
