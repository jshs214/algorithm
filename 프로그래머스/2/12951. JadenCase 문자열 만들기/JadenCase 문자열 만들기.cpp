#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> v;

string solution(string s) {
    string answer = "";

    
    while(true){
        int _pos = s.find(' ');
        
        if(_pos != -1){    
            string str = s.substr(0, _pos);
            str += " ";
            s = s.substr(_pos+1, s.length());
            v.push_back(str);
        }
        else
            break;
    }
    // 마지막 문자열
    v.push_back(s);
    
    for(string str : v){
        for(int i = 0; i < str.size(); i++){
            if(i ==0){
                if(str[i] >= 'a' && str[i] <='z'){
                    str[i] -=  32;
                }
            }
            else{
                if(str[i] >= 'A' && str[i] <='Z'){
                    str[i] +=  32;
                }
            }
        }
        
        
        answer += str;
    }
    
    
    
    return answer;
}