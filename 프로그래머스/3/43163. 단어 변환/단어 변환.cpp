#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> v;
string _begin;
string _target;

bool visited[5];
int ret = 98765432;
// 한개 알파벳만 바꿔지는지
bool convert1(string begin, string word){
    int cnt =0;
    for(int i = 0; i<begin.size(); i ++){
        if(begin[i] != word[i] ){
            cnt ++;   
        }
    }
    return (cnt <= 1)? true : false;
}

void dfs(int here, string str, int cnt){
    // 전부 탐색 전 target 찾은 경우
    if(str == _target){
        ret = min(ret, cnt);
        return;
    }


    for(int i = 0; i <v.size(); i ++){
        if(convert1( str, v[i]) && !visited[i]){
            visited[i] =true;
            dfs(i, v[i],cnt+1);
            visited[i] = false;
        }    
    }
    
    return;
}

int solution(string b, string t, vector<string> words) {
    int answer = 0;
    
    _begin = b;
    _target =t;
    v = words;
    
    dfs(0, b, 0);
    
    (ret == 98765432) ? answer = 0 : answer = ret;
    
    return answer;
}