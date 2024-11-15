#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<pair<int, int>> curios;
vector<int> backpack;

int ret = 0;
int main() {
	cin >> n >> k;

	// °ñµ¿Ç° v
	for (int i = 0; i < n; i++) {
		int m, v;
		cin >> m >> v;
		curios.push_back({ m,v });
	}
	// backpack
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		backpack.push_back(x);
	}

	sort(curios.begin(), curios.end());
	sort(backpack.begin(), backpack.end());
	
	priority_queue<int> pq;
	int idx = 0;
	for (int i = 0; i < k; i++) {
		while ( idx< n && curios[idx].first <= backpack[i]) {
			pq.push(curios[idx].second);
			idx++;
		}
		if (pq.size()) {
			ret += pq.top(); pq.pop();
		}
	}

	cout << ret<<'\n';

	return 0;
}
