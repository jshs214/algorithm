#include <bits/stdc++.h>
using namespace std;

int pSum[1100][1100];
int n, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> pSum[i][j];
			pSum[i][j] += pSum[i][j - 1] + pSum[i - 1][j] - pSum[i - 1][j - 1] ;
		}
	}
	
	// logic;
	int x1, y1, x2, y2;
	for (int i = 0; i < m; i++) {
		cin >> x1 >> y1 >> x2 >> y2;

		int ret = pSum[x2][y2] - pSum[x1 - 1][y2] - pSum[x2][y1-1] + pSum[x1 - 1][y1 - 1];
		cout << ret << '\n';
	}

	return 0;
}