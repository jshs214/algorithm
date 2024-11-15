#include <bits/stdc++.h>
using namespace std;
#define y1 aa

int n, x, y, x1, y1, x2, y2;

vector<int> checkX, checkY;		//꼭지점 좌표
int _y[1000004], _x[1000004];	// count 배열
pair<int, int> a[100004];

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;

		x += 500000;
		y += 500000;

		a[i] = { x, y };

		checkX.push_back(x);
		checkY.push_back(y);
	}
	a[n] = a[0];

	for (int i = 0; i < n; i++) {
		x1 = a[i].first;
		y1 = a[i].second;
		x2 = a[i + 1].first;
		y2 = a[i + 1].second;


		if (x1 != x2) {
			if (x1 > x2) swap(x1, x2);
			for (int j = x1 + 1; j <= x2; j++)
				_x[j]++;

		}
		if (y1 != y2) {
			if (y1 > y2) swap(y1, y2);
			for (int j = y1 + 1; j <= y2; j++)
				_y[j]++;
		}
	}
	
	int ret = -987654321;

	for (int a : checkX) ret = max(ret, _x[a]);
	for (int a : checkY) ret = max(ret, _y[a]);

	cout << ret;

	return 0;
}