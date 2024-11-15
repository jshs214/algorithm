#include <bits/stdc++.h>
using namespace std;
long long n, m, a, b, c, dist[1004], INF = 987654321;
vector<pair<int, int>> adj[1004];

int main() {

	cin >> n >> m;
	fill(dist, dist + n + 1, INF);
	
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		a--; b--;
		adj[a].push_back({ b,c });
	}

	dist[0] = 0;
	queue<int> q;

	for (int i = 0; i < n; i++) {
		for (int here = 0; here < n; here++) {
			for (auto there : adj[here]) {
				int d = there.second;
				int to= there.first;

				if (dist[here] != INF && dist[here] + d < dist[to]) {
					if (i == n - 1) q.push(to);
					dist[to] = dist[here] + d;
				}

			}
		}
	}

	if (q.size()) cout << -1 << "\n";
	else for (int i = 1; i < n; i++)
		cout << (dist[i] == INF ? -1 : dist[i]) << '\n';

	return 0;
}