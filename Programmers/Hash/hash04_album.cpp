#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool compare (pair<string,int> &a, pair<string,int> &b) {
    return a.second > b.second;
}
bool compare_all (pair<int,int> &a, pair<int,int> &b) {
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> strMap;
    map<int, int> all;
    int index = 0;
    for(auto elem : genres){
        if(strMap.end() == strMap.find(elem)){
            strMap.insert(make_pair(elem, plays[index]));
        }else
            strMap[elem] += plays[index];
        index++;
    }
    
    for (int i = 0; i < plays.size(); i++){
        all.insert(make_pair(i, plays[i]));
    }
    
    vector<pair<string, int>> vec;
    vector<pair<int, int>> all_vec;

	// copy key-value pairs from the map to the vector
    map<string, int> :: iterator it2;
    for (it2=strMap.begin(); it2!=strMap.end(); it2++) 
    {
        vec.push_back(make_pair(it2->first, it2->second));
    }
    
    map<int, int> :: iterator it1;
    for (it1=all.begin(); it1!=all.end(); it1++) 
    {
        all_vec.push_back(make_pair(it1->first, it1->second));
    }
    
    sort(vec.begin(), vec.end(), compare);
    sort(all_vec.begin(), all_vec.end(), compare_all);

    
    for (int i = 0; i < vec.size(); i++){
        int check = 0;
        for (int j = 0; j < all_vec.size(); j++){
            if (((vec[i].first).compare(genres[all_vec[j].first]))==0 && check < 2){
                check++;
                cout << vec[i].first << "\t" << all_vec[j].first << "\n";
                answer.insert(answer.end(), all_vec[j].first);
            }
        }
    }
    
    return answer;
}
