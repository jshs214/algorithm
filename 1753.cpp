#include <bits/stdc++.h>

using namespace std;

#define INF 987654321

int V, E, K, u, v, w;

// first  : 거리
// second : 노드
vector<pair<int, int>> adj[20005];
int dist[20005];

priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> >> pq;

int main() {
	cin >> V >> E >> K;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		adj[u].push_back({ w, v });
	}

	fill(dist, dist + 20001, INF);

	pq.push({ 0, K });
	dist[K] = 0;

	while (pq.size()) {
		int here_dist = pq.top().first;
		int here = pq.top().second;
		pq.pop();


		if (dist[here] != here_dist) continue;

		for (auto there : adj[here]) {
			int _dist = there.first;
			int _there = there.second;

			if (dist[_there] > dist[here] + _dist) {
				dist[_there] = dist[here] + _dist;

				pq.push({ dist[_there], _there });
			}

		}
	}

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF)  puts("INF");
		else cout << dist[i] <<"\n";
	}


	return 0;
}