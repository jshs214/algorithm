#include <bits/stdc++.h>
using namespace std;

int n, m, result = INT_MAX;
int a[300000];

bool search(int n) {
	int ret = 0;
	for (int i = 0; i < m; i++) {
		ret += a[i] / n;
		if (a[i] % n) ret++;
	}

	return ret <= n;
}
int main() {
	cin >> n >> m;

	int left = 1;
	int right =0;
	int mid;

	for (int i = 0; i < m; i++) {
		cin >> a[i];
		right = max(right, a[i]);
	}

	while (left <= right) {
		mid = (left + right) / 2;

		if (search(mid)) {
			result = min(result, mid);
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	return 0;
}