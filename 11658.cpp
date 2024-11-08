#include <bits/stdc++.h>
using namespace std;

#define max_n 1025
int y;
int a[max_n][max_n], tree[max_n][max_n];
int n, m;

int sum(int y, int x) {
	int ans = 0;
	while (y > 0) {
		int j = x;
		while (j > 0) {
			ans += tree[y][j];
			j -= (j & -j);
		}
		y -= (y & -y);
	}
	return ans;
}
void update(int y, int x, int value) {
	while (y <= n) {
		int j = x;
		while (j <= n) {
			tree[y][j] += value;
			j += (j & -j);
		}
		y += (y & -y);
	}
	return;
}

int main() {
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			// y, x
			update(i, j, a[i][j]);
		}
	}

	while (m--) {
		int w;
		cin >> w;
		// x,y를 c로 바꾸기
		if (w == 0) {
			int x, y, c;
			cin >> x >> y >> c;

			int diff = c - a[y][x];
			a[y][x] = c;
			update(y, x, diff);
		}
		// x1,y1 ~ x2,y2 합
		else {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;

			cout << sum(y2, x2) - sum(y2, x1 -1) - sum(y1 -1, x2) + sum(y1 -1, x1-1) <<"\n";
		}
	}

	return 0;
}