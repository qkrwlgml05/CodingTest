#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare (int a, int b){
    return a-b<0;
}

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size(), index_l = 0, index_r = 0;
    sort(lost.begin(), lost.end(), compare);
    sort(reserve.begin(), reserve.end(), compare);
    
    index_l = 0, index_r = 0;
    while (index_l < lost.size() && index_r < reserve.size()){
        if (lost[index_l] < reserve[index_r]-1){
            index_l++;
        }else if (lost[index_l] > reserve[index_r]+1){
            index_r++;
        }else{
            answer++;
            
            if (lost[index_l] == reserve[index_r+1]){
                index_r++;
            }else if (lost[index_l+1] == reserve[index_r]){
                index_l++;
            }
            
            index_l++;
            index_r++;
        }
    }
    return answer;
}
