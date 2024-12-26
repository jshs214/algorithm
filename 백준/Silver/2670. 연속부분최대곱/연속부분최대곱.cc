#include <bits/stdc++.h>
using namespace std;

double a[10004];

int n;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	double d = a[0];
	double ret = d;

	for (int i = 1; i < n; i++) {
		if (a[i] > d * a[i])
			d = a[i];
		else
			d *= a[i];
		ret = max(d, ret);
	}
	printf("%.3lf", ret);
		




	return 0;
}