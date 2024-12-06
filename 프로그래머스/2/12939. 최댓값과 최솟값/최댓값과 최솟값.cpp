#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;
string solution(string s) {
    string answer = "";
    
    while(true){
        int _pos = s.find(" ");
        if(_pos != -1){
            string str = s.substr(0, _pos);
            s = s.substr(_pos+1, s.length());
            int num = stoi(str);
            v.push_back(num);
        }else{
            int num = stoi(s);
            v.push_back(num);
            break;
        }
    }
    
    sort(v.begin(), v.end());
    answer = to_string(v[0]) + " " + to_string(v[v.size()-1]);
    return answer;
}