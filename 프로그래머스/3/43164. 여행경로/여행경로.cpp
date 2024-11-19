#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, vector<string> > m;

vector<string> v;
int totalTickets;

bool dfs(string here){
    v.push_back(here);
    
    if(v.size() == totalTickets +1)
        return true;
    
    for(int i = 0; i < m[here].size(); i++){
        string there = m[here][i];
        
        m[here].erase(m[here].begin() + i);
        
        if(dfs(there))
            return true;
        
        m[here].insert(m[here].begin() + i, there);
    }
    v.pop_back();
    
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;

    // 티켓 정보를 map에 저장
    for(vector<string> i : tickets){
        m[i[0]].push_back(i[1]);
    }
    
    // 사전순 정렬
    for (auto &entry : m) {
        sort(entry.second.begin(), entry.second.end());
    }
    
    totalTickets = tickets.size();
    
    dfs("ICN");

    answer = v;
    
    
    
    return answer;
}