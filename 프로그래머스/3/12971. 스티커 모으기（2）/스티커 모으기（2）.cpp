#include <iostream>
#include <vector>
using namespace std;

int dp[100004];
int dp2[100004];

int solution(vector<int> sticker)
{
    int answer =0;
    
    vector<int> v;
    v = sticker;

    // 0번째 부터 (마지막 못뽑음)
    dp[0] = v[0];
    dp[1] = dp[0];
    for(int i = 2; i < v.size(); i ++){
        if(i == v.size() -1){
            dp[i] = dp[i-1];
            break;
        }
        
        dp[i] = max(dp[i-2]+ v[i], dp[i-1] );
    }
    
    // 1번째 부터 (마지막 뽑음)
    dp2[0] = 0;
    dp2[1] = v[1];
    for(int i = 2; i < v.size(); i ++){
        dp2[i] = max(dp2[i-2]+ v[i], dp2[i-1] );
    }
    
    answer = max(dp[v.size()-1], dp2[v.size()-1]);
    
    return answer;
}