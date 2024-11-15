#include <bits/stdc++.h>
using namespace std;

#define MOD 1000007
int n, m, c, y, x, a[51][51], dp[51][51][51][51];
const int mod = 1000007;

int go(int y, int x, int cnt, int prev) {
	if (y > n || x > m) return 0;
	if (y == n && x == m) {
		if (cnt == 0 && a[y][x] == 0)	return 1;
		else if (cnt == 1 && a[y][x] > prev) return 1;
		return 0;
	}

	int& ret = dp[y][x][cnt][prev];
	if (ret != -1) return ret;

	ret = 0;
	if (a[y][x] == 0) {
		ret = (go(y + 1, x, cnt, prev) + go(y, x + 1, cnt, prev)) % MOD;
	}
	else if (a[y][x] > prev) {
		ret = (go(y + 1, x, cnt -1, a[y][x]) + go(y, x + 1, cnt -1, a[y][x])  ) % MOD;
	}

	return ret;
}

int main() {
	cin >> n >> m >> c;

	memset(a, 0, sizeof(a));
	memset(dp, -1, sizeof(dp));
	
	for (int i = 1; i <= c; i++) {
		cin >> y >> x;
		a[y][x] = i;
	}

	for (int i = 0; i <= c; i++)
		cout << go(1, 1, i, 0) << " ";



	return 0;
}