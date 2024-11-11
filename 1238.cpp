#include <bits/stdc++.h>
using namespace std;

// 플로이드 워셜은 400 이하
int n, m, x;
vector<pair<int, int>> adj[1001], Radj[1001];
int dist[1001], Rdist[1001];
const int INF = 987654321;

void dijkstra(int dist[], vector<pair<int,int>>* adj) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	
	dist[x] = 0;
	pq.push({ 0, x });

	while (pq.size()) {
		int here = pq.top().second;
		int here_dist = pq.top().first;
		pq.pop();

		if (dist[here] != here_dist) continue;

		for (pair<int, int> i : adj[here]) {
			int _there = i.second;
			int _dist = i.first;
			if (dist[_there] > dist[here] + _dist) {
				dist[_there] = dist[here] + _dist;
				pq.push({ dist[_there], _there });
			}
		}

	}


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m>> x;

	fill(dist, dist + 1001, INF);
	fill(Rdist, Rdist + 1001, INF);


	for (int i = 0; i < m; i++) {
		int a, b, t;
		cin >> a >> b >> t;
		adj[a].push_back({ t, b });
		Radj[b].push_back({ t, a });
	}

	dijkstra(dist, adj);
	dijkstra(Rdist, Radj);

	int ret = -987654321;
	for (int i = 1; i <= n; i++) {
		if (i == x) continue;
		ret = max(ret, dist[i] + Rdist[i]);
	}
	
	cout << ret;
	

	return 0;
}