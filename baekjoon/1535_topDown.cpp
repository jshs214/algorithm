#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int>> v;
int dp[104][22];

int go(int piro, int idx) {
	if (idx == n || piro <=0) return 0;

	int& ret = dp[piro][idx];
	if (ret != -1) return ret;

	// 안고르고 갈때
	ret = go(piro, idx + 1);

	if (piro - v[idx].first > 0) {
		ret = max(ret, go(piro - v[idx].first, idx + 1) + v[idx].second);
	}

	return ret;
}



int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int piro;
		cin >> piro;
		v.push_back({ piro, 0 });
	}
	for (int i = 0; i < n; i++) {
		int happy;
		cin >> happy;
		v[i].second = happy;
	}

	memset(dp, -1, sizeof(dp));

	cout << go(100, 0);
		

	return 0;
}