#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100005];
int visited[100005];
int result[100005];

int n, m, r;
int cnt = 0;

void dfs(int here) {
	visited[here] = 1;
	cnt++;
	result[here] = cnt;

	for (auto there : adj[here]) {
		if (visited[there]) continue;
		dfs(there);
	}

	return;
}

int main() {
	cin >> n >> m >> r;

	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		adj[s].push_back(e);
		adj[e].push_back(s);
	}

	for (int i = 0; i < 100005; i++) {
		if (adj[i].empty()) continue;
		sort(adj[i].begin(), adj[i].end());
	}

	dfs(r);

	for (int i = 1; i <= n; i++) {

		cout << result[i] << "\n";
	}

	return 0;
}