#include <bits/stdc++.h>

using namespace std;

int a[1004][1004];
int dp[1004][1004];
int n, m;

bool check(int y, int x) {
	if (y < 0 || y >= n || x < 0 || x >= m) return false;
	return true;
}

int solve(int y, int x) {
	if (y == n - 1 && x == m - 1) 
		return a[y][x];

	if (!check(y, x)) return 0;

	int& ret = dp[y][x];
	if (ret != -1) return ret;

	ret = a[y][x];

	int maxValue = -987654321;
	maxValue = max(maxValue, solve(y + 1, x) );
	maxValue = max(maxValue, solve(y, x + 1) );
	maxValue = max(maxValue, solve(y+1, x + 1) );

	ret += maxValue;

	return ret;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	
	memset(dp, -1, sizeof(dp));

	cout << solve(0, 0);

	return 0;
}