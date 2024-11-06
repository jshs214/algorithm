#include <bits/stdc++.h>
using namespace std;

int a[44];
int n, m, x;

// 구간 별 수
vector<int> v;

int dp[44];

int solve(int num) {
    if (num == 0) return 1; // 빈 구간일 경우 1가지 경우의 수
    if (num == 1) return 1;
    if (num == 2) return 2;

    int& ret = dp[num];
    if (ret) return ret;

    ret = solve(num - 1) + solve(num - 2);
    return ret;
}

int main() {
    cin >> n >> m;

    solve(n);

    fill(a, a + 44, 1);

    for (int i = 0; i < m; i++) {
        cin >> x;
        x--;
        a[x] = 0;
    }

    // 모든 좌석이 고정석이면 1
    if (n == m) {
        cout << "1";
        return 0;
    }

    int _count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            _count++;
        }
        else {
            if (_count > 0) v.push_back(solve(_count));
            _count = 0;
        }
    }
    if (_count > 0) v.push_back(solve(_count)); // 마지막 구간 처리

    int result = 1;
    for (auto i : v) {
        result *= i;
    }
    cout << result;

    return 0;
}
