#include <bits/stdc++.h>
using namespace std;

int lis[104];
pair<int, int> P[104];

int len = 0, n;

int main() {
	cin >> n;

	fill(lis, lis + 104, INT_MAX);

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		P[i].first = a;
		P[i].second = b;
	}

	sort(P, P + n);

	for (int i = 0; i < n; i++) {
		int num = P[i].second;
		auto lowerPos = lower_bound(lis, lis + len, num);

		if (*lowerPos == INT_MAX) len++;
		*lowerPos = num;

	}

	cout << n - len;

	return 0;
}