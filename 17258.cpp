#include <bits/stdc++.h>
using namespace std;

int n, m, k, t, a, b;

int cnt[301];
int dp[301][301];

vector<pair<int, int>> v;

// 인덱스, 영선이 남은 친구, 전에 쓴 영선이 친구
int go(int here, int num, int prev) {
	if (here == v.size()) return 0;
	if (dp[here][num]) return dp[here][num];

	int cost = max(0, t - v[here].second);
	int real_cost = (prev >= cost) ? 0 : cost - prev;

	int& ret = dp[here][num];
	//if (cost == 0) prev = 0;
	if (num - real_cost >= 0) {
		ret = max(go(here + 1, num - real_cost, cost) + v[here].first,
			go(here + 1, num, prev));
	}
	else ret = go(here + 1, num, prev);


	return ret;
}
int main() {
	cin >> n >> m >> k >> t;

	for (int j = 0; j < m; j++) {
		cin >> a >> b;
		for (int i = a; i < b; i++)
			cnt[i] = min(t, ++cnt[i]);
	}


	int temp = cnt[1];
	int _count = 1;		//구간 길이

	for (int i = 2; i <= n; i++) {
		if (temp != cnt[i]) {
			v.push_back({ _count, temp });
			_count = 0;
			temp = cnt[i];
		}
		_count++;
	}
	v.push_back({ _count, temp });	// 마지막 구간

	cout << go(0, k, 0);


	return 0;
}