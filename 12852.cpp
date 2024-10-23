#include <bits/stdc++.h>
using namespace std;

int x;
int dp[1000004];

int _div(int num, int mom) {
	int ret = 10e9;
	if (! (num % mom) ) {
		int idx = num / mom;
		ret = dp[idx] +1;
	}

	return ret;
}
int _minus1(int num) {
	int ret = 10e9;
	num -= 1;

	ret = dp[num] + 1;

	return ret;
}

void go(int here) {
	if (here == 0) return;

	cout << here << " ";
	if ( ! (here % 3)  && dp[here] == (dp[here /3]  +1 ) )
		go(here / 3);
	else if ( !(here % 2) && dp[here] == (dp[here /2] +1) )
		go(here / 2);
	else if ((here - 1 >= 0) && dp[here] == (dp[here - 1] ) +1 )
		go(here - 1);

	return;
	
}

int main() {
	
	cin >> x;

	dp[1] = 0;
	for (int i = 2; i <= x; i++) {
		if (!(i % 3) && !(i % 2))
			dp[i] = min(_div(i, 2), _div(i, 3));
		else if (!(i % 3) ) 
			dp[i] = min(_div(i, 3), _minus1(i));
		else if (!(i % 2))
			dp[i] = min(_div(i, 2), _minus1(i));
		else dp[i] = _minus1(i);
	}

	cout << dp[x] << "\n";
	go(x);

	return 0;
}