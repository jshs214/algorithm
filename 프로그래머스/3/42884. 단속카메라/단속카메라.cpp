#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

        // start, end
vector<pair<int,int>> v;

int solution(vector<vector<int>> routes) {
    int answer = 0;
        
    for(int i = 0; i <routes.size(); i ++){
        // logic 짜고 30000 으로 수정해야함
        routes[i][0] +=30005;
        routes[i][1] +=30005;
        
        v.push_back({routes[i][1], routes[i][0]});
    }
    
    sort(v.begin(), v.end());
    // {end, start}
    
    
    int lastP = v[0].first;
    int idx = 1;
    
    while(idx < v.size()){
        // 구간이 겹치는 경우
        if( lastP >= v[idx].second){
            idx++;
        }
        else{
            answer++;
            lastP = v[idx].first;
            
            idx++;
        }
    }
    answer++;
    
    return answer;
}