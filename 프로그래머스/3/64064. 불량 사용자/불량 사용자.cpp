#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int visited[10];
vector<string> userV;
vector<string> banV;
set<set<string>> sss;       //답이되는 리스트

int ret = -987654321;

bool check(string user, string ban){
    if(user.size() != ban.size())
        return false;
    
    for(int i = 0; i <user.size(); i ++){
        if(user[i] == ban[i]) continue;
        if(user[i] != ban[i] && ban[i] =='*') continue;
        return false;
    }

    return true;
}

void dfs(int here, set<string> list){
    if(here == banV.size()){
        sss.insert(list);
        return;
    }
    
    for(int i = 0; i < userV.size(); i++){
        if(visited[i]) continue;
        if(! check(userV[i], banV[here])) continue;
        
        visited[i] =1;
        
        set<string> nList = list;
        nList.insert(userV[i]);
        
        dfs(here+1, nList);
        
        visited[i] = 0;
        
    }
        
    
    
    
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    

    userV = user_id;
    banV = banned_id;
    
    set<string> s;
    dfs(0, s);
    
    answer = sss.size();
    
    
    return answer;
}