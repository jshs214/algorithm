#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int> > minpq;
priority_queue<int> pq;

vector<int> v;

void solve(char c, int num){
    if(c == 'D'){
        if( v.empty()) return;
        
        if(num == -1){     // 최솟값 삭제
            v.erase(min_element(v.begin(), v.end()));
        }
        else if(num == 1){ //최댓값 삭제
            v.erase(max_element(v.begin(), v.end()));
        }
        
    }
    else if(c =='I'){
        v.push_back(num);
    }
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;
        
    for(string i : operations){
        char c = i[0];
        int num;
        string st;
        
        int pos = st.find("-");
        
        if(pos == 0){   // -1 있는거
            st = i.substr(4, i.length());
            num = stoi(st);
            num *=-1;
        }
        else{
            st = i.substr(2, i.length());
            num = stoi(st);
        }
        
        solve(c, num);
    }
    
    for(int i : v){
        pq.push(i);
        minpq.push(i);
    }
    
    if(pq.empty() && minpq.empty()){
        return {0, 0};
    }
    
    return {pq.top(), minpq.top()};
}