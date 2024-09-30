#include <bits/stdc++.h>
using namespace std;


int t, n, m;
int a, b;
vector<int> adj[1004];
int visited[1004];

void dfs(int here) {
	visited[here] = 1;
	for (int there : adj[here]) {
		if (!visited[there]) dfs(there);
	}
	return;

	
}

int main() {
	cin >> t;

	for (int i = 0; i < t; i++) {

		for (int j = 0; j < 1004; j++) {
			adj[j].clear();
		}
		memset(visited, 0, sizeof(visited));

		cin >> n;
		cin >> m;

		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (!visited[j]) {
				dfs(j);
				cnt++;
			}
		}

		// V = E-1
		if (m == n-1 && cnt == 1) {
			cout << "tree" << '\n';
		}
		else cout << "graph" << '\n';

	}

	return 0;
}