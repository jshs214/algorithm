#include <bits/stdc++.h>
using namespace std;

int a[100004];
int n, x;
int cnt = 0;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> x;

	sort(a, a + n);

	int s = 0;
	int e = n - 1;
	
	while (s < e) {
		int value = a[s] + a[e];

		if (value > x)
			e--;
		else if (value < x) {
			s++;
		}
		else {
			s++;
			cnt++;
		}	
	}

	cout << cnt;

	return 0;
}