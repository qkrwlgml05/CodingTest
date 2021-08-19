#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end(), greater<int>());
    for (int i = 0; i < people.size(); i++){
        answer++;
        if (people[i]+people[people.size()-1] > limit)
            continue;
        people.pop_back();
    }
    return answer;
}
