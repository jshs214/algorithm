#include <bits/stdc++.h>
using namespace std;

double x, y;
int z;
int cnt = -1;

bool check(int mid) {
	int temp = z;

	double _y = y + mid;
	double _x = x + mid;

	int _z = _y * 100 / _x;

	if (z < _z)
		return true;


	return false;
}

int main() {
	cin >> x >> y;

	z = y * 100 / x;
	int temp = z;

	int left = 1;
	int right = 1000000002;
	int mid;
	
	while (left <= right) {
		mid = (left + right) / 2;

		if (check(mid)) {
			right = mid - 1;
			cnt = mid;
		}
		else
			left = mid + 1;

	}

	cout << cnt;

	return 0;
}