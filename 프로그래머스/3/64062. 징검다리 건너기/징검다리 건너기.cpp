#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<int> stones, int k, int mid){
    int cnt = 0;
    
    for(int i = 0; i < stones.size(); i ++){
        if(stones[i] < mid) cnt++;
        else cnt = 0;
        
        if(cnt >=k) return false;
    }
    return true;
}
int solution(vector<int> stones, int k) {
    int answer = 0;
    
    int l = 1;
    int r = *max_element(stones.begin(), stones.end());
    
    while(l<=r){
        int mid = (l + r) /2;
        
        if(check(stones, k, mid)){
            l = mid +1;
            answer = mid;
        }
        else r= mid-1;
    }
    
    
    
    return answer;
}