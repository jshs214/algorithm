#include <bits/stdc++.h>
using namespace std;

int a[55][55];
int temp[55][55];

int n, m, t;

// ╩С
int dy1[] = {0, -1, 0, 1};
int dx1[] = {1, 0, -1, 0};
// го
int dy2[] = { 0, 1, 0, -1 };
int dx2[] = { 1, 0, -1, 0 };

vector<pair<int, int>> v1, v2;

void broaden() {
	fill(&temp[0][0], &temp[0][0] + 55 * 55, 0);

	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != -1 && a[i][j]) {
				q.push({ i, j });
			}
		}
	}

	while (q.size()) {
		int y, x;
		tie(y, x) = q.front(); q.pop();

		int spread = a[y][x] / 5;

		for (int i = 0; i < 4; i++) {
			int ny = y + dy1[i];
			int nx = x + dx1[i];
	
			if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == -1) continue;

			temp[ny][nx] += spread;
			a[y][x] -= spread;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] += temp[i][j];
		}
	}	
}

vector<pair<int, int>> chung(int sy, int sx, int dy[], int dx[]) {
	vector<pair<int, int>> v;
	
	int cnt = 0;
	int y = sy;
	int x = sx;

	while(true) {
		int ny = y + dy[cnt];
		int nx = x + dx[cnt];

		if (ny == sy && nx == sx) break;

		if (ny < 0 || nx < 0 || ny >= n || nx >= m) {
			cnt++;
			ny = y + dy[cnt];
			nx = x + dx[cnt];
		}

		if (ny == sy && nx == sx) break;

		y = ny; x = nx;
		v.push_back({ y,x });
	}

	return v;
}
void go(vector<pair<int,int>>v) {
	for (int i = v.size() - 1; i > 0; i--) {
		a[v[i].first][v[i].second] = a[v[i - 1].first][v[i - 1].second];
	}

	a[v[0].first][v[0].second] =0;

	return;
}

int main() {
	cin >> n >> m >> t;

	bool flag = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == -1) {
				if (flag) {
					v1 = chung(i, j, dy1, dx1);
					flag = false;
				}
				else {
					v2 = chung(i, j, dy2, dx2);
				}
			}
		}
	}


	while (t--) {
		broaden();
		go(v1);
		go(v2);
	}

	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != -1)
				ret += a[i][j];
		}
	}

	cout << ret;

	return 0;
}