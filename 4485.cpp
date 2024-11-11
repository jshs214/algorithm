#include <bits/stdc++.h>
using namespace std;

const int max_n = 134;
const int INF = 987654321;

int n;
int adj[max_n][max_n];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0 ,1 };

void dijkstra(int dist[][max_n]) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push({ adj[0][0] , 0 });
	dist[0][0] = adj[0][0];

	while (pq.size()) {
		int hereY = pq.top().second / 1000;
		int hereX = pq.top().second % 1000;
		int here_dist = pq.top().first;
		pq.pop();

		if (dist[hereY][hereX] != here_dist) continue;

		for (int i = 0; i < 4; i++) {
			int ny = hereY + dy[i];
			int nx = hereX + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

			int _dist = adj[ny][nx];
			if (dist[ny][nx] > dist[hereY][hereX] + _dist) {
				dist[ny][nx] = dist[hereY][hereX] + _dist;
				pq.push({ dist[ny][nx], ny * 1000 + nx });
			}

		}
	}
}
int main() {
	int cnt = 1;
	while (true) {
		cin >> n;
		if (n == 0) break;

		fill(&adj[0][0], &adj[0][0] + max_n * max_n, INF);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) 
			cin >> adj[i][j];
		}

		int dist[max_n][max_n];
		fill(&dist[0][0], &dist[0][0] + max_n * max_n, INF);

		dijkstra(dist);

		cout << "Problem " << cnt << ": ";
		cout << dist[n - 1][n - 1] << "\n";
		cnt++;
	}


	return 0;
}