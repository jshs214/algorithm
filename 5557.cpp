#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int answer;
int a[104];

ll dp[104][22], n;

ll go(int idx, ll prevNum) {
	if (prevNum < 0 || prevNum >20) return 0;
	if (idx == n - 2) {
		if (prevNum == answer) return 1;
		return 0;
	}

	ll& ret = dp[idx][prevNum];
	if (ret) return ret;



	ret += go(idx + 1, prevNum + a[idx + 1]);
	ret += go(idx + 1, prevNum - a[idx + 1]);

	return ret;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	answer = a[n - 1];

	memset(dp, 0, sizeof(dp));
	
	cout << go(0, a[0]) << "\n";

	return 0;
}