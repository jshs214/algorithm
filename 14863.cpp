#include <bits/stdc++.h>
using namespace std;

int n, k;

int INF = 987654321;

// 시간, 도시
int dp[100005][104];


// 시간, 돈
vector<pair<int, int>> onFoot;
vector<pair<int, int>> bicycle;

int go(int time, int idx) {
	if (idx == n) return 0;

	int& ret = dp[time][idx];
	if (ret != -1) return ret;

	// 둘다 
	ret = -INF;
	if (time - onFoot[idx].first >= 0) {
		//ret = onFoot[idx].second;
		//ret = go(time - onFoot[idx].first, idx + 1) + onFoot[idx].second;
		ret = max(ret, go(time - onFoot[idx].first, idx + 1) + onFoot[idx].second);
	}
	if (time - bicycle[idx].first >= 0) {
		//ret += bicycle[idx].second;
		//ret += go(time - bicycle[idx].first, idx + 1);
		ret = max(ret, go(time - bicycle[idx].first, idx + 1) + bicycle[idx].second);
	}

	return ret;
}

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		onFoot.push_back({ a, b });
		bicycle.push_back({ c,d });
	}

	memset(dp, -1, sizeof(dp));

	cout << go(k, 0);

	return 0;
}