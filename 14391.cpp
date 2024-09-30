#include <bits/stdc++.h>
using namespace std;

int ret = -INT_MAX;
int n, m;

int a[5][5];


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			a[i][j] = s[j]-'0';
		}
	}

	//경우의 수
	for (int i = 0; i < (1 << n*m); i++) {
		int sum = 0;

		// width check
		for (int y = 0; y < n; y++) {
			int cur = 0;
			for (int x = 0; x < m; x++) {
				int idx = y * m + x;
				
				if ( (i & (1 << idx) )== 0) {
					cur = cur * 10 + a[y][x];
				}
				else {
					sum += cur;
					cur = 0;
				}
				//logic
			}
			sum += cur;
		}
		// height check
		for (int x = 0; x < m; x++) {
			int cur = 0;
			for (int y = 0; y < n; y++) {
				int idx = y * m + x;

				if ((i & (1 << idx)) != 0) {
					cur = cur * 10 + a[y][x];
				}
				else {
					sum += cur;
					cur = 0;
				}
			}
			sum += cur;
		}

		ret = max(ret, sum);
	}

	cout << ret;

	return 0;
}