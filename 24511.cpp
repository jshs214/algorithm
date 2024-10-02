#include <bits/stdc++.h>
using namespace std;

int n;
int m;
int a[100004];

queue<int> q;
stack<int> st;

#define QUEUE 0
#define STACK 1

int solve(int c) {
    if (a[0] == QUEUE) {
        queuestack_q[0].push(c);
        c = queuestack_q[0].front();
        queuestack_q[0].pop();
    }
    else if (a[0] == STACK) {
        queuestack_s[0].push(c);
        c = queuestack_s[0].top();
        queuestack_s[0].pop();
    }

    for (int i = 1; i < n; i++) {
        if (a[i] == QUEUE) {
            queuestack_q[i].push(c);
            c = queuestack_q[i].front();
            queuestack_q[i].pop();
        }
        else if (a[i] == STACK) {
            queuestack_s[i].push(c);
            c = queuestack_s[i].top();
            queuestack_s[i].pop();
        }
    }

    return c;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++) {
        int input;

        if (a[i] == STACK) {
            st.push(input);
        }
    }

    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    cin >> m;
    
    for (int i = 0; i < m; i++) {
        int c;
        cin >> c;
        q.push(c);
    }
    for (int i = 0; i < m; i++) {
        cout << q.front() << " ";
        q.pop();
    }


    return 0;
}
