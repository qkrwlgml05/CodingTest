#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b){
    return a[0] < b[0];
}

int solution(vector<vector<int>> routes) {
    int answer = 0, end = 0;
    sort(routes.begin(), routes.end(), compare);
    
    for (int i = 0; i < routes.size(); i++){
        if (i!=0 && routes[i][0] <= end) {
            end = end>routes[i][1]?routes[i][1]:end;
            continue;
        }
        end = routes[i][1];
        answer++;
    }
    return answer;
}
