#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
const int max_n = 505;
int dp[max_n][max_n];
int a[max_n], psum[max_n];
int tc, k;

int solve(int start, int end) {
	if (start == end)
		return 0;

	int& ret = dp[start][end];
	if (ret != -1) return ret;

	ret = INF;

	for (int i = start; i < end; i++) {
		ret = min(ret, solve(start, i) + solve(i + 1, end) + psum[end] - psum[start - 1]);
	}
	return ret;
}
int main() {
	cin >> tc;

	while (tc--) {
		fill(a, a + max_n, 0);
		fill(psum, psum + max_n, 0);
		fill(&dp[0][0], &dp[0][0] + max_n * max_n, -1);
		cin >> k;

		for (int i = 1; i <= k; i++) {
			cin >> a[i];
			psum[i] = psum[i - 1] + a[i];
		}

		cout << solve(1, k) <<"\n";



	}

	return 0;
}