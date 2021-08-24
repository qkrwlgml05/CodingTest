#include <string>
#include <vector>
#include <iostream>

using namespace std;

// int best(vector<vector<int>> tri, int curr){
//     if(tri.size()==1) return tri[0][curr];
//     int best_0 = best(vector<vector<int>>(tri.begin()+1, tri.end()), curr);
//     int best_1 = best(vector<vector<int>>(tri.begin()+1, tri.end()), curr+1);
//     return best_0>best_1?tri[0][curr]+best_0:tri[0][curr]+best_1;
// }

int best(vector<vector<int>> tri){
    vector<int> check;
    for (int i = tri.size()-1; i >= 0; i--){
        for(int j = 0; j < tri[i].size(); j++){
            if (i==tri.size()-1) check.push_back(tri[i][j]);
            else check[j] = check[j]>check[j+1]?tri[i][j]+check[j]:tri[i][j]+check[j+1];
        }
    }
    return check[0];
}

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    return best(triangle);
}
