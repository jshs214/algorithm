#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    
    int idx =0;
    
    for(int i = 1; i <=n; i ++){
        if(idx < stations.size() && i >= stations[idx] - w){
            i = stations[idx] + w;
            idx++;
        }
        else{
            answer++;
            i+=w*2;
        }
    }
    
    

    return answer;
}