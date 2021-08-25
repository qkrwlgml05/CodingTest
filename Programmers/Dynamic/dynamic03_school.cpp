#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare (vector<int> a, vector<int> b){
    return a[1]==b[1]?a[0]<b[0]:a[1]<b[1];
}
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0, index = 0;
    vector<int> prev (m+1,0), curr(m+1,1);
    sort(puddles.begin(), puddles.end(), compare);
    prev[0] = 1;
    for (int i = 0; i < n; i++){
        curr[0] = prev[0];
        for (int j = 0; j <= m; j++){
            if (index < puddles.size() && puddles[index][0]==j+1 && puddles[index][1]==i+1) {
                curr[j]=-1;
                index++;
            } else if (j!=0) curr[j] = ((curr[j-1]==-1?0:curr[j-1])+(prev[j]==-1?0:prev[j]))%1000000007;
        }
        prev.swap(curr);
    }
    return prev[m-1]%1000000007;
}
