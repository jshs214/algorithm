#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    int mok = s/n;
    int namuji = s % n;
    
    
    if(mok == 0){
        answer.push_back(-1);
        return answer;
    }
    
    while( answer.size() < n){
        if(namuji == 0)
            answer.push_back(mok);
        else{
            answer.push_back(mok+1);
            namuji--;
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}