#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int visited[20004];
vector<int> adj[20004];

int ret = -987654321;


void bfs(int here, int cnt){

    queue<int> q;
    visited[here] = 1;
    q.push(here);
    
    while(q.size()){
        int here = q.front();
        q.pop();
        
        for(auto there : adj[here]){
            if(visited[there]) continue;
            visited[there] = visited[here] +1;
            q.push(there);
            
            ret = max(ret, visited[there]);
            
        }
    }
     
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for(vector<int> i : edge){
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    

    bfs(1, 0);
    
    cout << ret;
    
    for(int i = 0; i < 20004; i ++){
        if(!adj[i].size()) continue;
        
        if(visited[i] == ret)
            answer++;    
    }

    
    return answer;
}