#include <bits/stdc++.h>
using namespace std;

int _start, _end;
vector<pair<int, int>> l;
int n;
int ret;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> _start >> _end;
		l.push_back({ _end, _start});
	}

	sort(l.begin(), l.end());


	_end = l[0].first;
	ret = 1;

	for (int i = 1; i < n; i++) {
		// 이전 end시간이 현재 start시간보다 작으면,
		if (_end <= l[i].second) {
			_end = l[i].first;
			ret++;
		}
	}

	cout << ret;


	return 0;
}