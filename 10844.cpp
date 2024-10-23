#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[101][10];
ll MOD = 1000000000;
int n;


int main() {
	cin >> n;

	dp[1][0] = 0;
	for (int i = 1; i <= 9; i++)
		dp[1][i] = 1;

	
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0)
				dp[i][j] = (dp[i - 1][j + 1]) % MOD;
			else if (j == 9)
				dp[i][j] = (dp[i - 1][j - 1]) % MOD;
			else {
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
			}
		}
	}

	
	ll cnt = 0;
	for (int i = 0; i <= 9; i++)
		cnt += dp[n][i];
	
	cout << cnt % MOD;

	

	return 0;
}