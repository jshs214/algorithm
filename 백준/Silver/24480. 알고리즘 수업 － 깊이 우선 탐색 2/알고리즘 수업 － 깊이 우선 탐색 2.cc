#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100004];
int visited[100004];

int n, m, r;
int cnt = 0;

void dfs(int here) {
	visited[here] = ++cnt;

	for (int there : adj[here]) {
		if (visited[there]) continue;
		dfs(there);
	}
}

int main() {
	cin >> n >> m >> r;
	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		adj[s].push_back(e);
		adj[e].push_back(s);
	}

	for (int i = 0; i < 100004; i++) {
		if (adj[i].size())
			sort(adj[i].begin(), adj[i].end(), greater<int>());
	}

	fill(visited, visited + 100004, 0);
	dfs(r);
	
	for (int i = 1; i <= n; i++)
		cout << visited[i] << "\n";
	



	return 0;
}