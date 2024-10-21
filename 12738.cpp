#include <bits/stdc++.h>

using namespace std;

const int L = 1000004;
int lis[L];
int len = 0;
int n;

int main() {
    cin >> n;

    fill(lis, lis + L, INT_MAX);

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        auto lowerPos = lower_bound(lis, lis + len, num);
        //int _pos = (int)(lowerPos - lis);
        if (*lowerPos == INT_MAX)len++;
        *lowerPos = num;
    }

    cout << len;

    return 0;
}