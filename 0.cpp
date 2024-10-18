#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll sum, ret = -1;
int n, m;
int a[1000005];

bool solve(ll mid) {
	ll height = 0;

	for (int i = 0; i < n; i++) {
		if ((ll)a[i] - mid > 0)
			height += (ll)a[i] - mid;
	}

	return height >= m;
}


int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}

	ll left = 1, mid;
	ll right = sum;

	while (left <= right) {
		mid = (left + right) / 2;

		if (solve(mid)) {
			left = mid + 1;
			ret = max(ret, mid);
		}
		else
			right = mid - 1;

	}

	if (ret <= 0) cout << "0";
	else
		cout << ret;

	return 0;
}