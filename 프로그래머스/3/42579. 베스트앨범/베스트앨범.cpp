#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include  <unordered_map>

using namespace std;

int N;

// 장르, 재생횟수 합
unordered_map<string, int> mp;

// 장르, 재생횟수, 고유번호
unordered_map<string, vector<pair<int,int>> > mp1;

bool cmp(const pair<string, int> & a, const pair<string,int> & b){
    return a.second > b.second;
}

bool cmp1(const pair<int, int>& a, const pair<int, int>& b){
    if(a.first == b.first)      // 재생 수 같으면 고유번호 작은거
        return a.second < b.second;
    return a.first > b.first;  // 아니면 재생수 큰거 부터
    
}



vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    N = genres.size();
    
    for(int i = 0 ; i< N; i++){
        mp[genres[i]] += plays[i];
        mp1[genres[i]].push_back({plays[i], i});
    }
    
    // 장르 재생횟수 합 정렬
    vector<pair<string, int>> v(mp.begin(), mp.end());
    sort(v.begin(), v.end(), cmp);

    // 장르, 재생횟수, 고유번호 정렬
    for(auto &x : mp1){
        sort(x.second.begin(), x.second.end(), cmp1);
    }
    
    for(auto x : v){
        for(int j = 0; j < mp1[x.first].size(); j++) {
            answer.push_back( mp1[x.first][j].second);
            if(j) break;
        }
    }
    
    
    
    
    
    return answer;
}