#include <bits/stdc++.h>
using namespace std;

int a[100005];
int psum[100005];

int n, ret = -INT_MAX;
int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		psum[i] = psum[i - 1] + a[i];
	}


	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			int num = psum[j] - psum[j-i];
			ret = max(ret, num);
		}
	}

	cout << ret;


	return 0;
}