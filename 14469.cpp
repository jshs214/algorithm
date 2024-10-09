#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;
int n;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a, b });
	}

	sort(v.begin(), v.end());

	int checkTime = v[0].first + v[0].second;
	int ret = 0;

	for (int i = 1; i < n; i++) {
		if (v[i].first < checkTime) {
			v[i].first += checkTime -v[i].first;
			checkTime += v[i].second;
		}
		else
			checkTime = v[i].first + v[i].second;

		cout << v[i].first << "," << v[i].second <<" : " << checkTime <<'\n';
	}


	

	return 0;
}