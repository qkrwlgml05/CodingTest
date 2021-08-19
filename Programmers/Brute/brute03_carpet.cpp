#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int pos_x = 0, pos_y = 0;
    
    pos_x = (sqrt((brown-4)*(brown-4)/4 - 4*yellow) + (brown-4)/2)/2;
    pos_y = (brown-4)/2 - pos_x;
    
    cout << pos_x << pos_y;
    
    answer.push_back(pos_x+2);
    answer.push_back(pos_y+2);
    
    return answer;
}
