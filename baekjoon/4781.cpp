#include <bits/stdc++.h>
using namespace std;

int n, c;
double m;

int dp[100004];

int main() {
	while (true) {
		cin >> n >> m;
		m += 0.0005;
		if (n == 0 ) break;
		
		int cost = m * 100;
		memset(dp, 0, sizeof(dp));

		for (int i = 0; i < n; i++) {
			cin >> c >> m;
			m += 0.0005;
			int p = m * 100;
			for (int j = p; j <= cost; j++) {
				dp[j] = max(dp[j], dp[j - p] + c);
			}
		}
		cout << dp[cost] <<'\n';
	}
	return 0;
}