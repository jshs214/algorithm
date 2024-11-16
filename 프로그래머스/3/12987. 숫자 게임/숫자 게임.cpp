#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int arrSize = A.size();
    
    int idxA = 0, idxB = 0;
    
    while(idxA < arrSize && idxB < arrSize){
        if( A[idxA] < B[idxB]){
            idxA++; idxB++;
            answer ++;
        } else{
            idxB++;
        }
        
    }
    
    
    return answer;
}