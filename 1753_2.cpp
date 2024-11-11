#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;

int v, e, s;
vector<pair<int, int>> adj[20005];
int dist[20005];

void dijkstra() {
    fill(dist, dist + 20005, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({ 0, s });
    dist[s] = 0;

    while (!pq.empty()) {
        int here = pq.top().second;
        int here_dist = pq.top().first;
        pq.pop();

        if (dist[here] != here_dist) continue;

        for (pair<int, int> there : adj[here]) {
            int _there = there.second;
            int _dist = there.first;

            if (dist[_there] > dist[here] + _dist) {
                dist[_there] = dist[here] + _dist;
                pq.push({ dist[_there], _there });
            }

        }
    }
}

int main() {
    cin >> v >> e >> s;

    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v,w });
    }

    dijkstra();

    //////////////////////////////////////

    for (int i = 1; i <= v; i++) { // i는 1부터 v까지 출력
        if (dist[i] != INF)
            cout << dist[i] << "\n";
        else
            cout << "INF\n"; // 도달할 수 없는 경우
    }

    return 0;
}
