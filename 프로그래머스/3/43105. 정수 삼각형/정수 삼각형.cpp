#include <iostream>
#include <string>
#include <vector>
using namespace std;

int dp[505][505];
int retValue;
vector<vector<int>> a;

// TOP down 풀이
// 효율성에서 일부 안됨
int solve(int here, int idx){
    if(here == a.size()){
        return a[here - 1][idx];
    }

    int &ret = dp[here][idx];
    if(ret != -1) return ret;
    
    ret = a[here][idx];
    
    int nextDown = solve(here + 1, idx);  // 직진
    int nextDiagonal = solve(here + 1, idx + 1);  // 대각선

    ret += max(nextDown, nextDiagonal);

    return ret;
}

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    // topDown
    //a = triangle;
    //fill(&dp[0][0], &dp[0][0]+505*505, -1);
    //answer = solve(0, 0);    

    int large;
    for(int i = triangle.size()-1; i>=0; i--){
        for(int j = 0; j < triangle[i].size()-1; j++){
            large = (triangle[i][j] > triangle[i][j+1]) ?
                triangle[i][j]:triangle[i][j+1];
            triangle[i-1][j] += large;
        }
    }
    
    answer = triangle[0][0];
    
    return answer;
}