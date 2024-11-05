#include <bits/stdc++.h>
using namespace std;

const int maxSize = 1004;

int px[maxSize], py[maxSize], dp[maxSize][maxSize];
int n, w;

int dist(int a, int b) {
	return abs(px[a] - px[b]) + abs(py[a] - py[b]);
}

int solve(int a, int b) {
	if (a == w + 1 || b == w + 1) return 0;

	int& ret = dp[a][b];
	if (ret) return ret;

	int next = max(a, b) + 1;

	ret = min(solve(a, next) + dist(b, next),
		solve(next, b) + dist(a, next));
	return ret;
}

void trace() {
	// 초기 경찰차
	int a = 0;
	int b = 1;
	
	for (int i = 2; i < w + 2; i++) {
		//1이 해결한게 작으면
		if (dp[i][b] + dist(a, i) < dp[a][i] + dist(b, i) ) {
			a = i;
			cout << "1\n";
		}
		else {
			b = i;
			cout << "2\n";
		}

	}

}

int main() {
	cin >> n;
	cin >> w;

	py[0] = 1; px[0] = 1;
	py[1] = n; px[1] = n;

	for (int i = 2; i < w + 2; i++) {
		int y, x;
		cin >> y >> x;
		py[i] = y;
		px[i] = x;
	}

	// 경찰차 두개
	cout << solve(0, 1);
	trace();

	return 0;
}