#include <bits/stdc++.h>
using namespace std;

#define INF 987654321
int n, k;
int a[10005];


int main() {
	cin >> n >> k;

	fill(a, a + 10005, INF);
	a[0] = 0;

	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		for (int j = temp; j <= k; j++) {
			a[j] = min(a[j], a[j - temp] + 1 );
		}
	}

	if (a[k] == INF) cout << -1;
	else cout << a[k];


	return 0;
}