#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(string a, string b){
    return a.compare(b) < 0;
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end(), compare);
    
    for (int i = 0; i < phone_book.size(); i++){
        for (int j = i+1; j < phone_book.size(); j++){
            if ((phone_book[j].compare(0, phone_book[i].size(), phone_book[i])) == 0){
                answer = false;
                return answer;
            }
        }
    }
    return answer;
}
