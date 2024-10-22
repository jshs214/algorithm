#include <bits/stdc++.h>
using namespace std;

int n;

void bottomUP() {
	int dp[1004];

	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= 1000; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}

	cin >> n;
	cout << dp[n] << "\n";
	return;
}

int memoization[1004];
int topDown(int n) {
	if (n < 2) return 1;

	if (memoization[n] != -1) return memoization[n];
	return memoization[n] =(topDown(n - 1) + topDown(n - 2)) % 10007;

}


int main() {
	//bottomUP();

	memset(memoization, -1, sizeof(memoization));
	int n;
	cin >> n;
	cout << topDown(n);
	return 0;
}