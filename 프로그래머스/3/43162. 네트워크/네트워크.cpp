#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<vector<int>> a;
int visited[201];

int N;

void dfs(int here){
    visited[here] =1;
    
    for(int i=0; i<N; i++) { 
    // current_computer와 연결된 컴퓨터들 탐색시작. 
    if(visited[i] == 0 && a[here][i] == 1) {   
      // 다른 컴퓨터와 연결되어 있고, 그 컴퓨터가 아직 탐색하지 않은 컴퓨터라면 탐색 시작
      dfs(i); 
    } 
  } 
}
int solution(int n, vector<vector<int>> computers) {
    a = computers;
    N = n;

    int answer = 0;
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < n; i++) {
        if(visited[i]) continue;
        dfs(i);
        answer++;
    }

    return answer;
}
