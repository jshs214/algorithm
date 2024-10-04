#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[10] = { 1,2,3,4,5,6,7, };

void solve(int start, vector<int> v) {
	if (v.size() == m) {
		for (auto i : v)
			cout << i << " ";
		cout << '\n';

		return;
	}

	for (int i = 1; i <= n; i++) {
		v.push_back(i);
		solve(i, v);
		v.pop_back();
	}
	

}

int main() {
	cin >> n >> m;

	vector<int> v;
	solve(0, v);

	return 0;
}