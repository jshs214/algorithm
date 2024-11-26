#include <bits/stdc++.h>
using namespace std;
double x, y;
int z;

bool binarySearch(int mid) {
	int newZ = (100 * (y + mid)) / (x + mid);

	if (newZ > z) return true;

	return false;
}

int main() {
	cin >> x >> y;
	z = 100 *y / x;
	
	if (y == x) {
		cout << -1;
		return 0;
	}

	

	int l = 1;
	int r = 1000000000;
	int answer;

	while (l<= r) {
		int mid = (l + r) / 2;
		if (binarySearch(mid)) {
			r = mid - 1;
			answer = mid;
		}
		else
			l = mid + 1;
	}

	cout << answer;

	return 0;
}