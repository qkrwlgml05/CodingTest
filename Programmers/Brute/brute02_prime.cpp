#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool check(string numbers, int num){
    string cpynumbers = numbers;
    for (int i = num; i > 0; i/=10){
        if (cpynumbers.find(to_string(i%10))==-1)
            return false;
        cpynumbers.erase(cpynumbers.find(to_string(i%10)), 1);
    }
    return true;
}


int primefind(int N, vector<int> prime){
    
    int theNumOfPrimes = 0; 
    bool checked[N + 1];   
    string nstring = to_string(N); 
    cout << nstring <<endl;
    
    for (int i = 2; i <= N; ++i)
    {
        if (checked[i] == false)
        {
            cout << i << endl;
            prime[theNumOfPrimes] = i;
            theNumOfPrimes++; 
        }
 
        for (int j = i * i; j <= N; j += i)
        {
            cout <<"i is true " << i << endl;
            checked[j] = true;
        }
        
    }
 
    int count = 0;
    for (int i = 0; i < theNumOfPrimes; ++i)
    {
        if(check(nstring, prime[i])){
                  cout << "enter: " << prime[i] << endl;
                  count++;
            }
    }
    
    return count;
    
}

int solution(string numbers) {
    int answer = 0;
    sort (numbers.begin(), numbers.end(), greater<char>());
    int n = std::stoi( numbers );
    cout << n << endl;
    
    vector<int> prime(n);
    answer =  primefind(n, prime);
    
    return answer;
}

//string으로 바꿔서 sorting 
//prime();
//비교
