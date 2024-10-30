#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, c, w, v;
ll a[34];

// w, v
vector<int> v1, v2;

void go(int here, int _n, vector<int>& v, int sum) {
	if (sum > c) return;
	if (here > _n) {
		v.push_back(sum);
		return;
	}
	go(here + 1, _n, v, sum + a[here]);
	go(here + 1, _n, v, sum);
	return;

}

int main() {
	cin >> n >> c;
	
	for (int i = 0; i < n; i++)
		cin >> a[i];

	go(0, n/2-1, v1, 0);
	go(n/2, n - 1, v2, 0);
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	ll ret =0;
	for (int b : v1) {
		if (c - b >= 0)
			ret += (int)(upper_bound(v2.begin(), v2.end(), c - b) - v2.begin());
	}

	cout << ret;
	return 0;
}
