#include <bits/stdc++.h>
using namespace std;

#define INF 987654321
int dist[1000][3];
int dp[1000][3];
int n;

int solve(int here, int prev) {
    if (here == n - 1) {
        return dist[here][prev];
    }

    int& ret = dp[here][prev];
    if (ret != INF) return ret;

    ret = INF;

    for (int i = 0; i < 3; i++) {
        if (i == prev) continue;
        ret = min(ret, solve(here + 1, i) + dist[here][prev]);
    }

    return ret;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> dist[i][j];
        }
    }

    fill(&dp[0][0], &dp[0][0] + 1000 * 3, INF);

    int ans = INF;
    for (int i = 0; i < 3; i++) {
        ans = min(ans, solve(0, i));
    }

    cout << ans << "\n";
    return 0;
}
