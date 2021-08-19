#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool check (string number, int index){
    for (int i = index+1; i < number.size(); i++){
        if (number[index] != number[i])
            return true;
    }
    return false;
}

string solution(string number, int k) {
    string answer = "";
    int i = 0, r = 0;
    while (i < number.size()){
        if (r >= k){
            break;
        }
        if (number[i] <= number[i+1] || i == number.size()-1){
            if (number[i] == number[i+1] && check(number, i)){
                i++;
                continue;
            }
            number.erase(number.begin()+i);
            r++;
            if (i != 0)
                i--;
        }else
            i++;
    }
    
    return number;
}
