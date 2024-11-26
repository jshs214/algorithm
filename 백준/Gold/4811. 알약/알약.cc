#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[33][33];
ll n;


ll go(ll whole, ll not_whole) {
	if (whole == 0 && not_whole == 0) return 1;

	ll& ret = dp[whole][not_whole];
	if (ret) return ret;

	if (whole > 0)
		ret += go(whole - 1, not_whole + 1);
	if (not_whole > 0)
		ret += go(whole, not_whole - 1);
	return ret;
}

int main() {

	while (true) {
		memset(dp, 0, sizeof(dp));
		cin >> n;

		if (n == 0) 	break;
		else
			cout << go(n, 0) << "\n";
	}
	return 0;
}