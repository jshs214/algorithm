#include <bits/stdc++.h>
using namespace std;

pair<int, int> P[1000004];
int n;

int ret = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;

		P[i] = { start,end };
	}

	
	sort(P, P +n);

	
	int s = P[0].first;
	int e = P[0].second;

	for (int i = 1; i < n; i++) {
		//구간이 끊어질 떄
		if (e < P[i].first) {
			ret += (e - s);
			s = P[i].first;
			e = P[i].second;
		}
		// 시작 겹치고 e가 연장될 때
		else if (P[i].first <= e && P[i].second >= e) {
			e = P[i].second;
		}
		
	}

	ret += e - s;

	cout << ret;

	return 0;
}