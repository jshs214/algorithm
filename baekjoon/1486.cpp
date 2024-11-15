#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;

int dist[30][30];
vector<int> v;		//1차원

int cost[3000][3000];

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0, -1,1 };

int ret;
int n, m, t, d;
string s;
int main() {
	cin >> n >> m >> t >> d;

	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] >= 'a' && s[j] <= 'z') {
				dist[i][j] = s[j] - 'a' + 26;
			}
			else dist[i][j] = s[j] - 'A';

			v.push_back(i * 100 + j);
		}
	}
	ret = dist[0][0];
	fill(&cost[0][0], &cost[0][0] + 3000 * 3000, INF);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int d = 0; d < 4; d++) {
				int ny = i + dy[d];
				int nx = j + dx[d];

				if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
				
				int height_diff = abs(dist[i][j] - dist[ny][nx]);
				if (height_diff <= t) {
					if (dist[ny][nx] > dist[i][j]) {
						cost[i * 100 + j][ny * 100 + nx] = height_diff * height_diff;
					}
					else
						cost[i * 100 + j][ny * 100 + nx] = 1;
				}

			}
		}
	}

	for (int k : v) {
		for (int i : v) {
			for (int j : v) {
				cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
			}
		}
	}

	for (int i : v) {
		if (d >= cost[0][i] + cost[i][0]) {
			// 비용 출력
			ret = max(ret, dist[i / 100][i % 100]);
		}
	}

	cout << ret;





	return 0;
}