#include <bits/stdc++.h>
using namespace std;

int t, n, m, tree[200004], temp;
map<int, int> mp;

void update(int i, int value) {
	while (i <= 200004) {
		tree[i] += value;
		i += (i & -i);
	}
}
int sum(int i) {
	int ret = 0;
	while (i > 0) {
		ret += tree[i];
		i -= (i & -i);
	}
	return ret;
}

int main() {
	cin >> t;

	while (t--) {
		cin >> n >> m;
		memset(tree, 0, sizeof(tree));
		mp.clear();
		
		int update_idx = 100001;

		for (int i = 1; i <= n; i++) {
			update(i + update_idx, 1);
			mp[i] = i + update_idx;
		}

		for (int i = 0; i < m; i++) {
			int temp;
			cin >> temp;
			int idx = mp[temp];
			cout << sum(idx) - 1 << " ";
			update(idx, -1);
			update(--update_idx, 1);
			mp[temp] = update_idx;
		}
		cout << "\n";

	}

}