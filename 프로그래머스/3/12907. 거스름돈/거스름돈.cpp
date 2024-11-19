#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int mod = 1000000007;
int dp[100004];


int solution(int n, vector<int> money) {
    int answer = 0;
    
    dp[0] = 1;
    for(int i = 0; i < money.size(); i ++){
        int num = money[i];
        
        for(int j = num; j<= n; j++){
            dp[j] += dp[j- num];    
        }
    }
    
    answer = dp[n]%mod;

    return answer;
}