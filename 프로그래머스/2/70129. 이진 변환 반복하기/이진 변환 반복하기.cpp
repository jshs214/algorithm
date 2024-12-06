#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int binaryConvert = 0;

string binary(int num) {
    string s = "";
    int zegob = 0;

    // 최대 자릿수 계산
    while (pow(2, zegob) <= num) {
        zegob++;
    }
    zegob--;

    while (zegob >= 0) {
        if (num >= pow(2, zegob)) {
            num -= pow(2, zegob);
            s += "1";
        } else {
            s += "0";
        }
        zegob--;
    }

    return s;
}

vector<int> solution(string s) {
    vector<int> answer (2, 0);
    
    while(s != "1"){
        int zeroCnt =0;
        for(int i = 0; i < s.size(); i ++){
            if(s[i] =='0')
                zeroCnt ++;
        }
        
        int len = s.size() - zeroCnt;
        answer[1] += zeroCnt;
        binaryConvert++;
        
        s = binary(len);
    }
    answer[0] = binaryConvert;
    
    return answer;
}