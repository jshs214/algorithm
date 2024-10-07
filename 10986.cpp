#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll pSum[1000005];
ll mod[1005];

ll sum;

int n, m;
ll cnt = 0;

// Start P 2
int combi(ll start) {
	int cnt = 0;
	cnt = start * (start - 1) / 2;
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		cin >> pSum[i];
		pSum[i] += pSum[i - 1];
	}


	for (int i = 1; i <= n; i++) {
		// m으로 떨어지는 개수
		mod[pSum[i] % m]++;
	}

	// 0 부터 mod개수 사이 cnt
	cnt += mod[0];

	for (int i = 0; i < m; i++) {
		if (mod[i] > 1) {
			cnt += combi(mod[i]);
		}
	}
	

	cout << cnt;

	  

	return 0;
}