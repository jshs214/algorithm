#include <bits/stdc++.h>
using namespace std;

char a[55][55];
int visited[55][55];

int n, m;

vector<pair<int, int>> area;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int ret = 0;

int bfs(int y, int x) {
	
	visited[y][x] = 1;
	queue<pair<int, int>> q;
	q.push({ y, x });

	int rett = 0;
	while (q.size()) {
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = yy + dy[i];
			int nx = xx + dx[i];

			
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (visited[ny][nx]) continue;
			if (a[ny][nx] == 'W') continue;

			visited[ny][nx] = visited[yy][xx] + 1;
			q.push({ ny, nx });

			rett = visited[ny][nx];
		}

	}

	return rett;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			a[i][j] = s[j];
			if (a[i][j] == 'L')
				area.push_back({ i,j });
		}
	}

	for (auto i : area) {
		memset(visited, 0, sizeof(visited));
		
		ret = max(ret, bfs(i.first, i.second));

	}

	cout << ret - 1;
	return 0;
}