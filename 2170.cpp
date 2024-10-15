#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;
int n;

int ret = 0;
int main() {
	cin >> n;
	
	
	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;

		v.push_back({ start,end });
	}

	
	sort(v.begin(), v.end());

	
	int s = v[0].first;
	int e = v[0].second;

	for (int i = 1; i < n; i++) {

		//구간이 끊어질 떄
		if (e < v[i].first) {
			ret += (e - s);
			s = v[i].first;
			e = v[i].second;
		}
		else if (v[i].first <= e && v[i].second >= e) {
			e = v[i].second;
		}
		
	}

	ret += e - s;

	cout << ret;

	return 0;
}