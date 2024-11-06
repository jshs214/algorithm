#include <bits/stdc++.h>
using namespace std;

int n, m, k, t, a, b;

// 시간 별 사람 count 배열
int cnt[301];
// use시간, 사람 수
vector<pair<int, int>> v;
// 구간v인덱스, 영선이 친구
int dp[301][301];

// 인덱스, 영선 친구, 이전에 사용
int go(int here, int num, int prev) {
	if (here == v.size()) return 0;

	int& ret = dp[here][num];
	if (ret) return ret;

	// 시간 별 필요한 영선이 친구 수
	int cost = max(0, t - v[here].second);
	// 현재 구간에 필요한 영선이 친구 수(이전 반영)
	int real_cost = (prev >= cost) ? 0 : cost - prev;

	ret = dp[here][num];
	if (cost == 0) prev = 0;

	//영선이 친구로 가능하면
	if (num - real_cost >= 0) {
		ret = max(go(here + 1, num - real_cost, cost) + v[here].first,
			go(here + 1, num, prev)) ;
	}
	// 불가 하면
	else
		ret = go(here + 1, num, 0);
	return ret;

}

int main() {
	cin >> n >> m >> k >> t;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		for (int j = a; j < b; j++) {
			cnt[j] = min(t, cnt[j] +1);
		}
	}

	int temp = cnt[1];
	int count = 1;

	for (int i = 2; i <= n; i++) {
		if (temp != cnt[i]) {
			v.push_back({ count, temp });
			count = 0;
			temp = cnt[i];
		}
		count++;
	}
	v.push_back({ count, temp });

	cout << go(0, k, 0);



	return 0;
}
