#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
int m, ret = INT_MAX;
int a[300004];

bool solve(int mid) {
	int ret = 0;
	for (int i = 0; i < m; i++) {
		ret +=a[i] / mid;
		if (a[i] % mid) ret++;
	}

	return ret <= n;
}

int main() {
	cin >> n >> m;

	int left = 1, right, mid;

	for (int i = 0; i < m; i++) {
		cin >> a[i];
		right = max(right, a[i]);
	}

	while (left <= right) {
		mid = (left + right) / 2;

		if (solve(mid)) {
			right = mid - 1;
			ret = min(ret, mid);
		}
		else {
			left = mid + 1;
		}
	}

	cout << ret;

	return 0;
}