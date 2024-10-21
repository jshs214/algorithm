#include <bits/stdc++.h>
using namespace std;

int n, m, sum, mx;
int a[100004];

bool solve(int mid) {
	// 써야되는 돈보다 최댓값이 크면
	if (mx > mid) return false;

	int temp = mid;
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		if (mid - a[i] < 0) {
			mid = temp;
			cnt++;
		}

		mid -= a[i];
	}

	if (mid != temp)
		cnt++;

	if (cnt == m) return true;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		mx = max(mx, a[i]);
	}

	int left = 0;
	int right = sum;
	int mid;

	int ret = INT_MAX;


	while (left <= right) {
		mid = (left + right) / 2;

		if (solve(mid)) {
			right = mid - 1;
			ret = mid;
		}
		else
			left = mid + 1;
	}

	cout << ret;

	return 0;
}