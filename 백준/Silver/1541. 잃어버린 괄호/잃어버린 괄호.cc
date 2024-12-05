#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int result = 0;
    int currentSum = 0;
    bool isNegative = false;

    string num = "";
    for (char ch : s) {
        if (isdigit(ch)) {  // 숫자인 경우
            num += ch;
        }
        else {            // 연산자인 경우
            currentSum += stoi(num);
            num = "";
            if (ch == '-') {
                if (isNegative) {
                    result -= currentSum;
                }
                else {
                    result += currentSum;
                }
                currentSum = 0;
                isNegative = true;
            }
        }
    }

    // 마지막 숫자 처리
    currentSum += stoi(num);
    if (isNegative) {
        result -= currentSum;
    }
    else {
        result += currentSum;
    }

    cout << result << endl;
    return 0;
}
