#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int mod =  1000000007;

int a[105][105];
int dp[105][105];
int N,M;


int solve(int y, int x){
    if(y == N && x == M) 
        return 1;
    
    int &ret = dp[y][x];
    if(ret != -1) return ret;
    
    ret = 0;
    
    if(y+1 <= N && a[y+1][x] != -1){
        ret += solve(y+1, x);
        ret = ret%mod;
    }
    if(x+1<= M && a[y][x+1] != -1){
        ret += solve(y, x+1);
        ret = ret%mod;
    }
    
    
    return ret;
}

int solution(int m, int n, vector<vector<int>> puddles) {
    N = n;
    M = m;
    int answer = 0;
    
    for(int i =1; i <=n; i ++){
        for(int j = 1; j <=m; j++){
            cin >>a[i][j];
        }
    }
    
    
    // 웅덩이 좌표 표시
    for (vector<int> puddle : puddles) {
        int x = puddle[0]; 
        int y = puddle[1]; 
        a[y][x] = -1;
    }
    fill(&dp[0][0] , &dp[0][0]  + 105 * 105, -1);
    
    answer = solve(1, 1);
    
    return answer;
}