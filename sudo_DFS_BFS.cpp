//BFS
#include <bits/stdc++.h>
using namespace std;

int here, there;
void bfs() {
	queue<int> q;
	q.push(here);

	while (q.size()) {
		here = q.front(); q.pop();

		for (int there : adj[here]) {
			if (visited[there]) continue;
			visitied[there] = vistied[here] + 1;
			q.push(there);
		}
	}
}

void dfs(int there) {
	if (vistied[there])return;
	vistied[there] = 1;

	for (int v : adj[there]) {
		if (visited[v] == 0)
			dfs(v);
	}

	return;
}