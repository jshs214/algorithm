// greedy 실패. 추후 dp로 다시풀기

#include <bits/stdc++.h>
using namespace std;

int n, k;

// W, V
vector<pair<int, int>> item;	

int ret = 0;

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int w, v;
		cin >> w >> v;
		item.push_back({ w, v });
	}

	sort(item.begin(), item.end());

	priority_queue<pair<int, int>> pq;


	for (int i = 0; i < n; i++) {
		if (item[i].first <= k) {
			pq.push(item[i]);
		}
		if (pq.size()) {
			ret += pq.top().second;
			k -= pq.top().first;
			pq.pop();
		}
	}


	cout << ret;

	return 0;
}