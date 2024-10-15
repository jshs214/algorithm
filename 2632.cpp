#include <bits/stdc++.h>
using namespace std;

int ret =0;
int pizza;

int m, n;

int a[1001];
int psum_a[2002];
int b[1001];
int psum_b[2002];

map<int, int> aCnt, bCnt;

void solve(int n, int psum[], map<int,int> &mp) {
	for (int interval= 1; interval <= n; interval++) {
		for (int start = interval; start <= n + interval - 1; start++) {
			int sum = psum[start] - psum[start - interval];
			mp[sum]++;
			if (interval == n) break;
		}

	}

}

int main() {
	cin >> pizza;
	cin >> n >> m;
	
	// a
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		psum_a[i] = psum_a[i - 1] + a[i];
	}
	for (int i = n + 1; i <= 2 * n; i++) {
		psum_a[i] = psum_a[i - 1] + a[i - n];
	}

	// b
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
		psum_b[i] = psum_b[i - 1] + b[i];
	}
	for (int i = m + 1; i <= 2 * m; i++) {
		psum_b[i] = psum_b[i - 1] + b[i - m];
	}

	solve(n, psum_a, aCnt);
	solve(m, psum_b, bCnt);
	
	//각각 피자
	ret = aCnt[pizza] + bCnt[pizza];

	for (int i = 1; i < pizza; i++) {
		ret += (aCnt[i] * bCnt[pizza - i]);
	}
	printf("%d\n", ret);

	return 0;
}