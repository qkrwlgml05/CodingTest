#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, std::vector<int>, std::greater<int>>
        sc(scoville.begin(), scoville.end());
    
    while (sc.size() != 1){
        int first = sc.top();
        if (first >= K)
            return answer;
        sc.pop();
        int second = sc.top();
        sc.pop();
        
        sc.push(first+2*second);
        answer += 1;
    }
    if (sc.top() >= K)
        return answer;
    return -1;
}
