#include <bits/stdc++.h>
using namespace std;

int n, k;

int main() {
	cin >> n >> k;

	int start = 1;
	int end = k;

	int result = -1;

	while (start <= end) {
		int cnt = 0;
		int mid = (start + end) / 2;

		// n x n 행렬에서 K번째 작은 원소를 찾을 때 
		// mid 이하의 개수를 세며 이분 탐색
		for (int i = 1; i <= n; i++) {
			cnt += min(mid / i, n);
		}

		if (cnt < k) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
			result = mid;
		}
	}

	cout << result;

	return 0;
}