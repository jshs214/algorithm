#include<bits/stdc++.h>
using namespace std;

int dp[1000005], n;

int f(int num) {
	int& ret = dp[num];
	if (ret != -1) return ret;

	ret = 0;
	ret += (f(num - 1) + f(num - 2)) % 15746;

	return ret;
}

int main() {
	cin >> n;

	memset(dp, -1, sizeof(dp));

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;

	cout << f(n);
	
	return 0;
}