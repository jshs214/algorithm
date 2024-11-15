#include <bits/stdc++.h>
using namespace std;

int dp[100004];
int n, w, v, k;

int main() {
	cin >> n >> k;
	
	for (int i = 0; i < n; i++) {
		cin >> w >> v;
		for (int j = k; j >= w; j--) {
			dp[j] = max(dp[j], dp[j - w] + v);
		}

	}

	cout << dp[k];

	return 0;
}