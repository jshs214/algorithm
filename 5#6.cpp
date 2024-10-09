// Line Swipping  : 정렬 -> 구간 재정의
#include <bits/stdc++.h>
using namespace std;

pair<int, int> L[1000004];
int n, from, to;
int ret = 0;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> from >> to;
		L[i] = { from, to };
	}

	sort(L, L + n);

	int l, r;
	l = L[0].first;
	r = L[0].second;

	for (int i = 1; i < n; i++) {
		if (L[i].first > r) {
			ret += (r - l);
			l = L[i].first;
			r = L[i].second;
		}
		if (L[i].first <= r && L[i].second >= r) {
			r = L[i].second;
		}
	}
	ret += r - l;
	cout << ret <<'\n';

	return 0;
}
