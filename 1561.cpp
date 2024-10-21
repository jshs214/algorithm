/// 241017 Ç®´Ù°¡ ¸¾.

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define max_n 60000000004

ll n, m, mid, l, r, ret;
ll a[10004];

bool check(ll mid) {

	int cnt = m;

	for (int i = 0; i < m; i++) {
		cnt += mid / a[i];
	}

	return cnt >= n;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}

	if (n <= m) {
		cout << n;
		return 0;
	}

	l = 1;
	r = max_n;

	while (l <= r) {
		mid = (l + r) / 2;

		if (check(mid)) {
			r = mid - 1;
			ret = mid;
		}
		else l = mid + 1;
	}



	return 0;
}