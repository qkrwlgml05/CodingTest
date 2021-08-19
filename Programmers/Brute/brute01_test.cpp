#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> check(3,0);
    vector<int> bans{1,3,4,5};
    vector<int> cans{3,1,2,4,5};
    
    for (int i = 0; i < answers.size(); i++){
        int a_ans = i % 5 + 1;
        int b_ans = 2;
        if (i%2==1)
            b_ans = bans[(i/2)%4];
        int c_ans = cans[(i/2)%5];
        
        if (answers[i] == a_ans)
            check[0] += 1;
        if (answers[i] == b_ans)
            check[1] += 1;
        if (answers[i] == c_ans)
            check[2] += 1;
        
    }
    
    int max = 0;
    
    for (int i = 1; i < check.size(); i++){
        if (check[i] > check[max])
            max = i;
    }
    answer.push_back(max+1);
    for (int i = max+1; i < max+3; i++){
        if (i == 0)
            break;
        if (check[i]==check[max])
            answer.push_back(i+1);
    }
    
    return answer;
}
