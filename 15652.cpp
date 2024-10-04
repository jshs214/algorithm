#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[10] = { 1,2,3,4,5,6,7,8,9, };

void solve(int start) {
	if (start == m) {
		for (int i = 0; i < m; i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';
		return;
	}

	int s;
	if (start > 0)
		s = a[start - 1];
	else s = 1;

	for (int i = s; i <= n; i++) {
		a[start] = i;
		solve(start + 1);
		a[start] = 0;
	}
}
int main() {
	cin >> n >> m;

	
	solve(0);

	return 0;
}