#include <bits/stdc++.h>
using namespace std;
#define max_N 16
#define INF 987654321

int dist[max_N][max_N];
int dp[max_N][(1 << max_N)];
int n;

int solve(int here, int visited) {
	if (visited == (1 << n) - 1) {

		return dist[here][0] ? dist[here][0] : INF;
	}

	int& ret = dp[here][visited];
	if (ret != -1) return ret;

	ret = INF;

	for (int i = 0; i < n; i++) {
		if (visited & (1 << i)) continue;
		if (dist[here][i] == 0) continue;

		ret = min(ret, solve(i, visited | (1 << i)) + dist[here][i]);
	}
	return ret;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> dist[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));

	cout << solve(0, 1);

	return 0;
}