#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[55][55];
int ret = INT_MAX;

// Start : B
int bsolve(int y, int x) {
	int cnt = 0;

	for (int i = y; i < y + 8; i++) {
		for (int j = x; j < x + 8; j++) {
			if (i % 2 == 0 && j % 2 == 0
				|| i % 2 == 1 && j % 2 == 1) {
				if (a[i][j] != 'B') cnt++;
			}
			else if (i % 2 == 0 && j % 2 == 1
				|| i % 2 == 1 && j % 2 == 0
				) {
				if (a[i][j] != 'W') cnt++;
			}
		}
	}


	return cnt;
}

// Start : W
int wsolve(int y, int x) {
	int cnt = 0;

	for (int i = y; i < y+8; i++) {
		for (int j = x; j < x+8; j++) {
			if (i % 2 == 0 && j % 2 == 0
				|| i % 2 == 1 && j % 2 == 1) {
				if (a[i][j] != 'W') cnt++;
			}
			else if (i % 2 == 0 && j % 2 == 1
				|| i % 2 == 1 && j % 2 == 0
				) {
				if (a[i][j] != 'B') cnt++;
			}
		}
	}

	return cnt;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			a[i][j] = s[j];
		}
	}

	for (int i = 0; i <= n-8; i++) {
		for (int j = 0; j <= m-8; j++) {
			ret = min(ret, wsolve(i, j));
			ret = min(ret, bsolve(i, j));
		}
	}

	cout << ret;

	return 0;
}