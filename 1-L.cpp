#include <bits/stdc++.h>

using namespace std;

int n, m;
int cnt = 0;
int a[16000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	cin >> n >> m;
	vector<int> b;
	int temp;

	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] + a[j] == m) cnt++;
		}
	}
	cout << cnt << "\n";

	return 0;
}