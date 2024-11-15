#include <bits/stdc++.h>
using namespace std;

int dp[1004][2][34];
int b[1004];

int t, w;

int go(int idx, int tree, int cnt) {
	if (cnt < 0) return -1e9;
	if (idx == t) return 0;

	int& ret = dp[idx][tree][cnt];
	if (~ret) return ret;

	return max( go(idx +1, tree ^ 1, cnt - 1),
		go(idx +1, tree, cnt) + (tree == b[idx] - 1) );

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> t >> w;
	for (int i = 0; i < t; i++)
		cin >> b[i];

	memset(dp, -1, sizeof(dp));
	cout << max(go(0, 1, w - 1), go(0, 0, w));

	
	return 0;
}