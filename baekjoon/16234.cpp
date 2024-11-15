#include <bits/stdc++.h>
using namespace std;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

int n, l, r;
int a[55][55];
int visited[55][55];

vector<pair<int, int> > v;
int sum = 0;
int cnt = 0;
int ret = 0;

bool whileFlag = true;

void check(int y, int x) {

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (visited[ny][nx]) continue;

		if (l <= abs(a[ny][nx] - a[y][x]) && r >= abs(a[ny][nx] - a[y][x]))
		{
			visited[ny][nx] = 1;
			v.push_back({ ny, nx });
			sum += a[ny][nx];
			cnt++;
			check(ny, nx);
		}

	}
}


int main() {

	cin >> n >> l >> r;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	// 반복 조건
	while (true) {
		bool flag = false;
		memset(visited, 0, sizeof(visited));
		
		// logic
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j]) {
					v.clear();
					visited[i][j] = 1;
					v.push_back({ i,j });

					sum = a[i][j];
					check(i, j);
					if (v.size() == 1)continue;
					for (pair<int, int> i : v) {
						a[i.first][i.second] = sum / v.size();
						flag = true;
					}

				}
			}
		}
		if (!flag) break;
		ret++;
	}


	cout << ret;


	return 0;
}