#include <bits/stdc++.h>
using namespace std;

int t, n, m;

int solve(int a[], int b[]) {

	sort(b, b + m);

	int cnt = 0;

	// a ¼øÈ¸
	for (int i = 0; i < n; i++) {
		int value = a[i];

		int left = 0, right = m -1;
		int mid;

		while (left <= right) {
			mid = (left + right) / 2;

			if (b[mid] < value) {
				left = mid + 1;
			}
			else
				right = mid - 1;
		}

		cnt += left;
	}

	return cnt;
}

int main() {
	cin >> t;

	for (int i = 0; i < t; i++) {
		int a[20004];
		int b[20004];

		cin >> n >> m;

		for (int j = 0; j < n; j++)
			cin >> a[j];

		for (int j = 0; j < m; j++)
			cin >> b[j];


		cout << solve(a, b)<<'\n';
	}

	return 0;
}