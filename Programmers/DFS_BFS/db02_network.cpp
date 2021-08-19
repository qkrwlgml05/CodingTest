#include <string>
#include <vector>

// 0 - white, 1 - gray, 2 - black

using namespace std;
vector<int> count(vector<vector<int>> computers, vector<int> color, int curr){
    color[curr] = 1;
    for (int i = 0; i < computers.size(); i++){
        if (i == curr || computers[curr][i] == 0 || color[i] != 0)
            continue;
        color = count(computers, color, i);
    }
    color[curr] = 2;
    return color;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<int> color(n, 0);
    
    for (int i = 0; i < computers.size(); i++){
        if (color[i] == 2)
            continue;
        color = count(computers, color, i);
        answer++;
    }
    return answer;
}
