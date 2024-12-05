#include <bits/stdc++.h>
using namespace std;

int a[1004], psum[1004];
int n;
int ret =0;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a+1 , a + n +1);

	for (int i = 1; i <= n; i++) {
		psum[i] = psum[i - 1] + a[i];
		ret += psum[i];
	}
	cout << ret;
	
	return 0;
}