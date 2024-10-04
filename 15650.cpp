#include <bits/stdc++.h>
using namespace std;

vector<int>v;

int n, m;
void combi(int start, vector<int> v) {
	if (v.size() == m) {
		//print
		for (auto i : v)
			cout << i << ' ';
		cout << '\n';

		return;
	}

	for (int i = start+1; i <= n; i++) {
		v.push_back(i);
		combi(i, v);
		v.pop_back();
	}
}
int main() {

	cin >> n >> m;
	combi(0, v);
	return 0;
}