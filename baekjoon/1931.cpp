#include <bits/stdc++.h>
using namespace std;

int from, to;
vector<pair<int, int>> l;
int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> from >> to;
		l.push_back({ to, from});
	}

	sort(l.begin(), l.end());


	to = l[0].first;
	int ret = 1;

	for (int i = 1; i < n; i++) {
		// 이전 end시간이 현재 start시간보다 작으면,
		if (to <= l[i].second) {
			to = l[i].first;
			ret++;
		}
	}

	cout << ret;


	return 0;
}