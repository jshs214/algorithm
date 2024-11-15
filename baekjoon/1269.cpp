#include <bits/stdc++.h>
using namespace std;

int a[200006];
int b[200006];

int result[200006];

int n, m;

bool check(int right, int find, int a[]) {
	int left = 0;

	while (left <= right) {
		int mid = (right + left) / 2;

		if (a[mid] < find) {
			left = mid + 1;
		}
		else if (a[mid] > find) {
			right = mid - 1;
		}
		else return true;

	}

	return false;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];

	sort(a, a + n);
	sort(b, b + m);

	set<int> sss;

	// a - b
	for (int i = 0; i < n; i++) {
		int value = a[i];
		int right = m - 1;
		if (! check(right, value, b)) {
			sss.insert(value);
		}
	}

	// a - b
	for (int i = 0; i < m; i++) {
		int value = b[i];
		int right = n - 1;
		if (!check(right, value, a))
			sss.insert(value);
	}


	cout << sss.size();

	return 0;
}