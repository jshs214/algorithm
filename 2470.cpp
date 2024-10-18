#include <bits/stdc++.h>
using namespace std;

int a[100005];
int n, mn, mx;
int ret = INT_MAX;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n);

	int l = 0, r = n-1;

	while (l <= r) {
		int sum = a[l] + a[r];

		if (sum == 0) {
			cout << a[l] << " " << a[r];
			return 0;
		}

		if (ret > abs(sum)) {
			ret = abs(sum);
			mn = a[l];
			mx = a[r];
		}

		if (sum > 0) {
			r--;
		}
		else if (sum < 0) {
			l++;
		}
	}

	cout << mn << " " << mx;


	


	return 0;
}