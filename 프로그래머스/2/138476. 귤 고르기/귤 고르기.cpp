#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<int,int> mp;
vector<pair<int,int>> v;

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    for(int i : tangerine){
        mp[i]++;
    }
    
    for(auto i : mp){
        v.push_back( {i.first, i.second });
    }
    
    sort(v.begin(), v.end(), cmp  );
    
    int ret = 0;
    for(int i = 0; i < v.size(); i ++){
        ret += v[i].second;
        answer ++;
        //귤 개수 되면
        if(ret >= k){
            break;
        }
    }
    
    
    
    return answer;
}