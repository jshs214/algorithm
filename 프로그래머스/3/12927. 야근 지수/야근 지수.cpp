#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

priority_queue<int> pq;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    for(int i : works)
        pq.push(i);
    
    while(n--){
        int num = pq.top();
        pq.pop();
        
        if(num >0)
            num--;
        pq.push(num);
    }
    
    if(pq.size() == 0)
        answer = 0;
    else{
        while(pq.size()){
            answer += pow(pq.top(), 2);
            pq.pop();
        }
    }
    
    
    return answer;
}