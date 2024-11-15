#include <bits/stdc++.h>
using namespace std;

int dp[1000004];
int n;

int _div(int num, int divNum) {
	int ret = INT_MAX;
	if (num % divNum == 0) {
		num = num / divNum;
		ret = dp[num] + 1;
	}
	return ret;
}
int _min(int num) {
	int ret = INT_MAX;
	num -= 1;

	ret = dp[num] + 1;

	return ret;
}

int main() {
	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= 1000000; i++) {
		int num;
		if (i % 6 == 0) {
			int temp = min(_div(i, 2), _div(i, 3));
			dp[i] = min(temp, _min(i));
		}
		else if (i % 2 == 0) {
			num = i / 2;
			dp[i] = min(_div(i,2), _min(i));
		}
		else if (i % 3 == 0) {
			num = i / 3;
			dp[i] = min(_div(i, 3), _min(i));
		}
		else {
			dp[i] = _min(i);
		}
	}


	cin >> n;
	cout << dp[n];

	return 0;
}