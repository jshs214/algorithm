#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    
    int len = a.size();
    vector<int>left (len);
    vector<int>right(len);
    
    int _min = a[0];
    for(int i = 0; i <len; i ++){
        _min = min(_min, a[i]);
        left[i] = _min;
    }
    
    _min = a[len-1];
    for(int i = len-1; i>=0; i--){
        _min = min(_min, a[i]);
        right[i] = _min;
    }
    
    
    
    
    // 양쪽 끝
    for(int i=0; i <len; i ++){   //양쪽 끝 제외
        if(a[i] > left[i] && a[i] > right[i]) continue;
        else answer++;

    }
    
    
    
    
    return answer;
}