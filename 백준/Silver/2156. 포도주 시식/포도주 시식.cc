#include <bits/stdc++.h>
using namespace std;

int a[10005];
int dp[10005][3];
int  n;

int solve(int here, int cnt) {
	if (here >= n ) {
		return 0;
	}

	int& ret = dp[here][cnt];
	if (ret != -1) return ret;

	// 안마시고 넘어간 경우
	ret = solve(here + 1, 0);

	if (cnt == 0) ret = max(ret, solve(here + 1, 1) + a[here]);
	if (cnt == 1) ret = max(ret, solve(here + 1, 2) + a[here]);


	return ret;
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	fill(&dp[0][0], &dp[0][0] + 10005 * 3, -1);

	cout << solve(0, 0);

	return 0;
}