// 4781 사탕가게 dp

#include <bits/stdc++.h>
using namespace std;

// caloles, pay

int dp[100004];

int main() {

	int n;		// 상근이 사탕 종류
	double m;	// 상근이 돈의 양
	int cost;		// 상근이 돈 정수 변환

	while(true) {
		cin >> n >> m;
		if (n == 0 && m == 0.00) break;
		m += 0.0005;

		cost = m * 100;

		fill(dp, dp + 100004, 0);
		
		for (int i = 0; i < n; i++) {
			int c; double p;
			cin >> c >> p;
			p += 0.0005;

			int nP = p * 100;
			
			for (int j = nP; j <= cost; j++) {
				dp[j] = max(dp[j], dp[j - nP] + c);
			}
		}

		cout << dp[cost] << "\n";
	}


	return 0;
}