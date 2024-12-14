#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

bool check(string s){
    stack<char> stk;
    
    for(int i = 0; i < s.size(); i ++){
        if(stk.size()  && stk.top() =='[' && s[i] ==']'){
            stk.pop();
            continue;
        }
        else if(stk.size()  && stk.top() =='(' && s[i] ==')'){
            stk.pop();
            continue;
        }
        else if(stk.size()  && stk.top() =='{' && s[i] =='}'){
            stk.pop();
            continue;
        }   
        
        
        stk.push(s[i]);
    }
    
    if(stk.size() ) 
        return false;
    else
        return true;
    
}
int solution(string s) {
    int answer = 0;
    
    if(check(s))
        answer ++;
    
    for(int i = 0; i < s.size()-1; i ++){
        rotate(s.begin(), s.begin()+1, s.end());
        if(check(s))
            answer ++;
    }
    
    
    return answer;
}