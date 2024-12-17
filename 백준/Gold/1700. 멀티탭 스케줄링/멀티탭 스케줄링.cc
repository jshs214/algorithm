// Memory Paging Optimal
#include <bits/stdc++.h>
using namespace std;

int n, k;

int a[104];
bool visited[104];
int ret = 0;

int main() {
	cin >> k >> n;

	vector<int> v;

	for (int i = 0; i < n; i++) 
		cin >> a[i];

	for (int i = 0; i < n; i++) {
		if (!visited[a[i]]) {
			if (v.size() == k) {
				int last_idx = 0, pos;
				
				for (int _a : v) {
					int here = INT_MAX;

					for (int j = i + 1; j < n; j++) {
						if (_a == a[j]) {
							here = j;
							break;
						}
					}
					if (last_idx < here) {
						last_idx = here;
						pos = _a;
					}
				}
				visited[pos] = 0;
				ret++;
				v.erase(find(v.begin(), v.end(), pos));
			}
			v.push_back(a[i]);
			visited[a[i]] = 1;
		}

	}
	
	cout << ret;

	return 0;
}
