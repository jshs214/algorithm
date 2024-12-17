#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 무게, 가치
vector<pair<ll, ll>> cubic;
vector<ll> backpack;


int n, k;
ll ret = 0;

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		ll w, v;
		cin >> w >> v;
		cubic.push_back({ w, v });
	}
	for (int i = 0; i < k; i++) {
		int w;
		cin >> w;
		backpack.push_back(w);
	}

	sort(cubic.begin(), cubic.end());
	sort(backpack.begin(), backpack.end());
	
	priority_queue<ll> pq;

	int j = 0;
	for (int i = 0; i < k; i++) {
		while (j < n && cubic[j].first <= backpack[i]) {
			pq.push(cubic[j].second);
			j++;
		}
		if (pq.size()) {
			ret += pq.top();
			pq.pop();
		}
		
	}
	cout << ret;

	return 0;
}