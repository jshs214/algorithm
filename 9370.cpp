/*
다익스트라, 경로를 지나는지 확인하는 문제

필수 경로 : 홀수 설정.
나머지 경로 : 짝수

-> 최단거리가 홀수면 경로 지남. 아니면 경로 지나지 않음.

*/
#include <bits/stdc++.h>
using namespace std;
const int INF = 987654322;	//짝수 설정

int tc;
int n, m, t, s, g, h;
int a, b, d;

void dijkstra(int dist[], vector<pair<int, int>> *adj) {
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	dist[s] = 0;
	pq.push({ 0, s });
	
	while (pq.size()) {
		int here = pq.top().second;
		int here_dist = pq.top().first;
		pq.pop();

		if ( dist[here] != here_dist) continue;

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
	cin >> tc;

	while (tc--) {
		cin >> n >> m >> t;
		cin >> s >> g >> h;
		
		vector<pair<int, int>> adj[2004];
		int dist[2004];

		fill(dist, dist + 2004, INF);

		for (int i = 0; i < m; i++) {
			cin >> a >> b >> d;
			
			// 모든 경로 짝수 처리
			d *= 2;

			// g-h 양방향 경로 홀수 처리
			if (a == g && b == h)
				d--;
			else if (a == h && b == g)
				d--;

			adj[a].push_back({ d, b });
			adj[b].push_back({ d, a });
		}

		vector<int> destination;
		for (int i = 0; i < t; i++) {
			int temp;
			cin >> temp;
			destination.push_back(temp);
		}
		sort(destination.begin(), destination.end());

		dijkstra(dist, adj);
		
		for (int i : destination) {
			if (dist[i] % 2 == 1)cout << i << " ";
		}
		cout << "\n";
	}

	return 0;
}

