#include <bits/stdc++.h>
using namespace std;

double a[10004];

int n;

double solve() {
	double mx = -INT_MAX;
	for (int i = 0; i < n; i++) {
		double curr = 1.0;
		cout << i << "\n";
		for (int j = i; j < n; j++) {
			curr *= a[j];
			mx = max(mx, curr);
			cout << j << " ";
		}
		cout << '\n';
	}

	return mx;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	//1. 단순 구현
	cout << solve();
	//// 2. greedy
	//double d = a[0];
	//double ret = d;

	//for (int i = 1; i < n; i++) {
	//	if (a[i] > d * a[i])
	//		d = a[i];
	//	else
	//		d *= a[i];
	//	ret = max(d, ret);
	//}

	//printf("%.3lf", ret);
		




	return 0;
}