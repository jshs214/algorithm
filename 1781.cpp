#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;

//	deadline, cupnoodle
vector<pair<int, int> > v;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int d, c;
		cin >> d >> c;
		v.push_back({ d, c });
	}
	
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		pq.push(v[i].second);
		if (pq.size() > v[i].first) {
			pq.pop();
		}
	}

	int ret = 0;
	while (pq.size()) {
		ret += pq.top();
		pq.pop();
	}
	cout << ret;

	return 0;
}