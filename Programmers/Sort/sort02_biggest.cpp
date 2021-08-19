#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;

bool compare (int a, int b){
    string sa = to_string(a);
    string sb = to_string(b);
    return a*pow(10,sb.size())+b > b*pow(10,sa.size())+a;
}

string solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end(), compare);
    string answer = "";
    for (int i = 0; i < numbers.size(); i++){
        answer += to_string(numbers[i]);
    }
    if (answer[0] == '0')
        return "0";
    return answer;
}
