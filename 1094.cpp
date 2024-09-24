#include <bits/stdc++.h>
using namespace std;

int ret;
int x;

int main() {
	cin >> x;

	if (x == 64) {
		cout << "1";
		return 0;
	}


	for (int i = 1; i <= (1 << 6); i++) {
		int sum = 0;

		int cnt = 0;
		for (int j = 0; j < 6; j++) {
			if (i & (1 << j)) {
				sum += (1 << j);
				cnt++;
			}
		}
		if (sum == x) {
			cout << cnt;
		}
	}



	return 0;
}