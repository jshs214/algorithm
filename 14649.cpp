#include <bits/stdc++.h>
using namespace std;

int N, Q;
int arr[101];
int cnt[3];

int main() {

	cin >> N >> Q;
	while (Q--) {
		int x; char c; cin >> x >> c;
		if (c == 'R') {
			x++;
			for (; x < 101; x++) arr[x]++;
		}
		else {
			x--;
			for (; x > 0; x--) arr[x]++;
		}
	}

	for (int i = 1; i < 101; i++) cnt[arr[i] % 3]++;
	for (int i = 0; i < 3; i++) {
		int x = N * cnt[i];
		cout << x / 100 << '.' << (x / 10) % 10 << x % 10 << '\n';
	}
	return 0;
}