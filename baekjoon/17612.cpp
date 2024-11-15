#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Cacher {
	int id, maxCost, cacherID;
};

struct cmp {
	bool operator()(const Cacher& a, const Cacher& b) {
		// 누적 계산 같으면. 작은 계산대 sort(pq는 반대) 
		if (a.maxCost == b.maxCost) {
			return a.cacherID > b.cacherID;
		}
		// 누적 계산 작게 sort(pq는 반대)
		return a.maxCost > b.maxCost;
	}
};

priority_queue<Cacher, vector<Cacher>, cmp> pq;

vector<Cacher> v;
bool cmpV(const Cacher& a, const Cacher& b) {
	if (a.maxCost == b.maxCost)
		return a.cacherID > b.cacherID;
	return a.maxCost < b.maxCost;
}

ll ret = 0;
int n, k;
int hid, costTime, cacherid;

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> hid >> costTime;

		if (i < k) {
			pq.push({ hid, costTime, i + 1 });
			continue;
		}
		pq.push({ hid, costTime + pq.top().maxCost, pq.top().cacherID });
		v.push_back({ pq.top() });
		pq.pop();
	}
	while (pq.size()) {
		v.push_back({ pq.top() });
		pq.pop();
	}
	sort(v.begin(), v.end(), cmpV);

	for (int i = 0; i < v.size(); i++) {
		ret += 1ll * v[i].id * (i + 1);
	}

	cout << ret;

	return 0;
}