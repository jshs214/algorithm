#include <bits/stdc++.h>
using namespace std;

int n, ret, cnt;
string s;
stack<int> st;

int d[200002];

int main() {
    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.push(i);
        }
        else if(s[i] ==')') {
            if (st.size()) {
                d[st.top()] = 1;    // '(' 위치
                d[i] = 1;           // ')' 위치
                st.pop();
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (d[i]) {
            cnt++;
            ret = max(ret, cnt);
        }
        else cnt = 0;
    }

    cout << ret << endl;

    return 0;
}
