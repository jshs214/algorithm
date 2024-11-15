#include <bits/stdc++.h>
using namespace std;

int n, m, s, e;
int a[2004];

int dp[2004][2004];

int solve(int s, int e) {
	if (s >= e) return 1;

	int& ret = dp[s][e];
	if (ret != -1) return ret;


	if (a[s] == a[e])
		ret = solve(s + 1, e - 1);
	else
		ret = 0;

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> a[i];


	cin >> m;

	memset(dp, -1, sizeof(dp));

	while (m--) {
		cin >> s >> e;
		cout << solve(s, e) << '\n';
	}


	return 0;
}