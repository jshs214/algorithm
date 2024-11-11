#include <bits/stdc++.h>
using namespace std;

int visited[100005];
vector<int> adj[100005], Radj[100005];
int n, m, x;

int bfs(int here, vector<int>adj[]) {
	queue<int> q;
	visited[here] = 1;
	q.push(here);

	int ret = 0;

	while (q.size()) {
		int _here = q.front();
		q.pop();
		
		for (int there : adj[_here]) {
			if (visited[there]) continue;
			visited[there] = 1;
			q.push(there);
			ret++;
		}
	}

	return ret;
}
int main() {
	cin >> n >> m >> x;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		Radj[b].push_back(a);
	}


	//내 앞
	int ans1 = bfs(x, Radj);
	fill(visited, visited + 100005, 0);
	// 내 뒤
	int ans2 = bfs(x, adj);

	cout << ans1 + 1 << " " << n - ans2;
	

	return 0;
}