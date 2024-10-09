// 아직 안품

#include <bits/stdc++.h>
using namespace std;

char a[2004][2004];
int pSum[2004][2004];

int n, m, k;

// bsolve & wsolve 재설계 pSum 개수 확인해야할듯.
 
// Start : B
int bsolve(int y, int x, int k) {
	int cnt = 0;

	for (int i = y; i < y + k; i++) {
		for (int j = x; j < x + k; j++) {
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
int wsolve(int y, int x, int k) {
	int cnt = 0;

	for (int i = y; i < y + k; i++) {
		for (int j = x; j < x + k; j++) {
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
	cin >> n >> m >> k;

	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			a[i][j] = s[j];
		}
	}

	return 0;
}