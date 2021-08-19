#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int count(vector<int> numbers, int target, int curr){
    if (numbers.size() == 0)
        return 0;
    
    int temp = curr-2*numbers[0];
    if (temp == target)
        return 1+count(vector<int>(numbers.begin()+1, numbers.end()), target, curr);
    if (temp>target)
        return count(vector<int>(numbers.begin()+1, numbers.end()), target, curr)+count(vector<int>(numbers.begin()+1, numbers.end()), target, temp);
    
    return 0;
}

int solution(vector<int> numbers, int target) {
    int answer = 0, curr = 0;
    sort(numbers.begin(), numbers.end(), less<int>());
    for (int i = 0; i < numbers.size(); i++){
        curr += numbers[i];
    }
    
    answer = count(numbers, target, curr);
    return answer;
}
