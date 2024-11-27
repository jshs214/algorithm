#include <string>
#include <vector>

using namespace std;

int dist[1004][1004];

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    
    int n = board.size();
    int m = board[0].size();
    
    fill(&dist[0][0], &dist[0][0] + 1004*1004, 0);
    
    for(auto sk : skill){
        int type = sk[0];
        int x = sk[1];
        int y = sk[2];
        int xx = sk[3];
        int yy = sk[4];
        int degree = sk[5];
        if(type ==1) degree *= -1;
        
        dist[x][y] += degree;
        dist[xx+1][yy+1] +=degree;
        dist[xx+1][y] -=degree;
        dist[x][yy+1] -=degree;
    }
    
    for(int i = 1; i <n; i++){
        for(int j = 0; j <m; j ++){
            dist[i][j] += dist[i-1][j];
        }
    }
    
    for(int j = 1; j <m; j ++){
        for(int i = 0; i <n; i++){
            dist[i][j] +=dist[i][j-1];
        }
    }
    
    for(int i = 0; i <n; i++){
        for(int j = 0; j <m; j++){
            board[i][j] +=dist[i][j];
            if(board[i][j] >0) answer++;
        }
    }
    
    
    
    
    
    
    
    return answer;
}