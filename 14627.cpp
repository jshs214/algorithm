#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int s, c;
int a[1000004];


ll sum;
ll ret = 0;

bool solve(ll value) {

	int cnt = 0;
	for (int i = 0; i < s; i++) {
		cnt += a[i] / value;
	}

	return cnt >= c;
}

int main() {
	cin >> s >> c;

	for (int i = 0; i < s; i++) {
		cin >> a[i];
		sum += a[i];
	}


	ll left = 1, mid;
	ll right = sum;

	while (left <= right) {
		mid = (right + left) / 2;


		if (solve(mid)) {
			left = mid + 1;
			ret = mid;
		}
		else
			right = mid - 1;
	}


	ll len = 0;
	len = sum - ret * c;
	cout << len;


	return 0;
}