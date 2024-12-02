#include <bits/stdc++.h>
using namespace std;

bool che[4000002];
int n, cnt =0;
vector<int> era(int mx_n) {
	vector<int> v;
	for (int i = 2; i <= mx_n; i++) {
		if (che[i]) continue;
		for (int j = 2 * i; j <= mx_n; j += i) {
			che[j] = 1;
		}
	}

	for (int i = 2; i <= mx_n; i++)
		if (che[i] == 0)v.push_back(i);

	return v;
}

int main() {
	cin >> n;

	vector<int> sosu;
	sosu = era(n);

	int l = 0;
	int r = 0;

	while (l <= r && r < sosu.size()) {
		int sum =0;
		for (int i = l; i <= r; i++) {
			sum += sosu[i];
		}
		if (sum > n)l++;
		else r++;

		if (n == sum) cnt++;
	}
	
	cout << cnt;
	
	return 0;
}