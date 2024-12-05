#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1004];
bool visited[10005];

int n, m, v;

void dfs(int here) {
	if (visited[here]) return;
	cout << here << " ";
	visited[here] = 1;

	for (int there : adj[here]) {
		if (visited[there]) continue;
		
		dfs(there);
	}
}
void bfs(int here) {
	queue<int> q;
	q.push(here);
	visited[here] = 1;

	while (q.size()) {
		int _here= q.front();
		q.pop();
		
		cout << _here << " ";
		for (int there : adj[_here]) {
			if (visited[there]) continue;
			visited[there] = true;
			q.push(there);
		}
	}
}

int main() {
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		adj[s].push_back(e);
		adj[e].push_back(s);
	}

	for (int i = 0; i < 1004; i++) {
		if (adj[i].size()) {
			sort(adj[i].begin(), adj[i].end());
		}
	}

	fill(visited, visited + 10005, 0);
	dfs(v);
	cout << "\n";
	fill(visited, visited + 10005, 0);
	bfs(v);

	return 0;
}