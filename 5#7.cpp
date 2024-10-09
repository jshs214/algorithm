#include <bits/stdc++.h>
using namespace std;

int n, x, ret = 0;
vector<int> v;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	cin >> x;


	sort(v.begin(), v.end());

	int r, l;
	l = 0;
	r = n - 1;

	while (l < r) {
		if (v[l] + v[r] == x) {
			r--;
			ret++;
		}
		else if (v[l] + v[r] < x) l++;
		else if (v[l] + v[r] > x) r--;
	}

	cout << ret;


	return 0;
} 