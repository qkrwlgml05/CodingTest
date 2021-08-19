#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> sorting_c;
    vector<string> column;
    int answer = 1;
    for(auto elem : clothes)
    {
        if(sorting_c.end() == sorting_c.find(elem[1])){
            sorting_c.insert(make_pair(elem[1], 1));
            column.insert(column.begin(), elem[1]);
        }else
            sorting_c[elem[1]]++;
    }
    
    for (int i = 0; i < sorting_c.size(); i++){
        answer*=(sorting_c.find(column[i])->second+1);
    }
    return answer-1;
}
