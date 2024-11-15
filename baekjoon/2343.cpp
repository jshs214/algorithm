#include<bits/stdc++.h>
using namespace std;

int n, m, sum =0, mx =0, ret;

int a[100004];

bool solve(int mid) {
	//블루레이 사이즈보다 최댓값이 크면
	if (mx > mid) return false;

	int temp = mid;
	int cnt = 0;
	
	for (int i = 0; i < n; i++) {	
		if (mid -a[i] < 0) {
			mid = temp;
			cnt++;
		}

		mid -= a[i];
	}

	if (mid != temp)
		cnt++;

	return cnt <= m;
}

int main() {
	cin >> n >> m;

	int left, mid, right;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		mx = max(mx, a[i]);
	}
	left = 0;
	right = sum;

	while (left <= right) {
		mid = (left + right) / 2;

		if (solve(mid)) {
			right = mid - 1;

			ret = mid;
		}
		else {
			left = mid + 1;
		}
	}

	cout << ret;

	return 0;
}