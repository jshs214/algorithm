#include<string>
#include <iostream>
#include <stack>
using namespace std;

stack<char> stk;

bool solution(string s)
{
    bool answer = true;

    for(int i = 0; i < s.size(); i ++){
        if(s[i] =='(')
            stk.push(s[i]);
        else{
            if(stk.size())
                stk.pop();
            else{
                answer = false;
                return answer;
            }
        }
    }
    
    if(stk.size())
        answer = false;
    else answer = true;
    
    return answer;
}