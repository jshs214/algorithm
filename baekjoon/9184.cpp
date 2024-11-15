#include <bits/stdc++.h>
using namespace std;

#define INF 987654321
int dp[22][22][22];

int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	if (a > 20 || b > 20 || c > 20)
		return w(20, 20, 20);

	int& ret = dp[a][b][c];
	if (ret != -1) return ret;

	ret = 0;
	if (a < b && b < c) {
		ret = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	}
	else
		ret = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);

	return ret;
}



int main() {
	int a, b, c;

	memset(dp, -1, sizeof(dp));

	while (true) {
		cin >> a >> b >> c;
		
		if (a == -1 && b == -1 && c == -1) break;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;

	}
	
	return 0;
}