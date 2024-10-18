#include <bits/stdc++.h>
using namespace std;

int n, c;
int a[200005];
int ret;

bool check(int mid) {
	// Ã¹ Áý
	int cnt = 1;
	int cur = a[0];

	for (int i = 1; i < n; i++) {
		if (a[i] - cur >= mid) {
			cnt++;
			cur = a[i];
		}
	}

	return cnt >= c;
}

int main() {
	cin >> n >> c;

	int mx =-1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
	}

	sort(a, a + n);

	int left = 0, mid;
	int right = mx;

	while (left <= right) {
		mid = (left + right) / 2;

		if (check(mid)) {
			left = mid + 1;
			ret = mid;
		}
		else right = mid - 1;
	
	}

	cout << ret;

	return 0;
}