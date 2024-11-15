#include <bits/stdc++.h>
using namespace std;

int s, e, val;
int n, m;

int a[100005];
int pSum[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	
	while (m--) {
		cin >> s >> e >> val;
		
		pSum[s] += val;
		pSum[e+1] -= val;
	}

	for (int i = 2; i <= n; i++) {
		pSum[i] = pSum[i - 1] + pSum[i];
	}

	for (int i = 1; i <= n; i++)
		cout << a[i] + pSum[i] << " ";


	return 0;
}