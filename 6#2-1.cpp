#include <bits/stdc++.h>
using namespace std;

int a[1004];
int cnt[1004];

int n;
int ret;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	
	for (int i = 0; i < n; i++) {
		int maxValue = 0;

		// 검사 idx 좌측 순회
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i] && maxValue < cnt[j]) {
				maxValue = cnt[j];
			}
		}

		cnt[i] = maxValue + 1;
		ret = max(ret, cnt[i]);
	}

	cout << ret;

	return 0;
}