#include <bits/stdc++.h>
using namespace std;

int n, m;

//가방
int a[104];

// 무게와 가방 인덱스?
int dp[10005][104];

vector<pair<int, int>> v;

int solve(int weight, int idx) {
	if (idx == v.size() || weight <= 0) return 0;

	int& ret = dp[weight][idx];
	if (ret != -1) return ret;

	ret = solve(weight, idx + 1);

	if (weight - v[idx].first >= 0) {
		ret = max(ret, solve(weight - v[idx].first , idx+1) + v[idx].second);
	}

	return ret;

}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int a, b, c;
		// 무게, 만족도, 개수
		cin >> a >> b >> c;
		for (int j = 0; j < c; j++) {
			v.push_back({ a,b });
		}
	}

	memset(dp, -1, sizeof(dp) );

	cout << solve(m, 0);

	return 0;
}