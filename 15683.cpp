#include <bits/stdc++.h>
using namespace std;

int a[10][10];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int n, m;

int dir = 0;
int ret = INT_MAX;

vector<pair<int, int>>v;

void CCTV(int here, int dir, int a[10][10]) {
	int y = v[here].first;
	int x = v[here].second;

	// CCTV 1
	if (a[y][x] == 1) {
		while (true) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] != 6) {
				if (a[ny][nx] == 0) {
					a[ny][nx] = -1;
				}

				y = ny;
				x = nx;
			}
			else	break;
		}
	}
	// CCTV2
	else if (a[y][x] == 2) {
		for (int i = 0; i <= 2; i += 2) {
			int _y = y;
			int _x = x;
			while (true) {
				int ny = _y + dy[(dir + i) % 4];
				int nx = _x + dx[(dir + i) % 4];
				if (ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] != 6) {
					if (a[ny][nx] == 0) {
						a[ny][nx] = -1;
					}

					_y = ny;
					_x = nx;
				}
				else break;

			}
		}
	}
	// CCTV 3
	else if (a[y][x] == 3) {
		for (int i = 0; i <= 1; i ++) {
			int _y = y;
			int _x = x;
			while (true) {
				int ny = _y + dy[(dir + i) % 4];
				int nx = _x + dx[(dir + i) % 4];
				if (ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] != 6) {
					if (a[ny][nx] == 0) {
						a[ny][nx] = -1;
					}

					_y = ny;
					_x = nx;
				}
				else break;
			}
		}
	}
	// CCTV 4
	else if (a[y][x] == 4) {
		for (int i = 0; i <= 2; i++) {
			int _y = y;
			int _x = x;
			while (true) {
				int ny = _y + dy[(dir + i) % 4];
				int nx = _x + dx[(dir + i) % 4];
				if (ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] != 6) {
					if (a[ny][nx] == 0) {
						a[ny][nx] = -1;
					}

					_y = ny;
					_x = nx;
				}
				else break;

			}
		}
	}
	//CCTV 5
	else if (a[y][x] == 5) {
		for (int i = 0; i <= 3; i++) {
			int _y = y;
			int _x = x;
			while (true) {
				int ny = _y + dy[(dir + i) % 4];
				int nx = _x + dx[(dir + i) % 4];
				if (ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] != 6) {
					if (a[ny][nx] == 0) {
						a[ny][nx] = -1;
					}

					_y = ny;
					_x = nx;
				}
				else break;
			}
		}
	}


}

void solve(int here, int board[10][10]) {
	if (here == v.size()) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] ==0) cnt++;
			}
		}
		ret = min(cnt, ret);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int temp[10][10];
		memcpy(temp, board, sizeof(temp));

		CCTV(here, i, temp);
		solve(here + 1, temp);
	}
	

}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] != 6 && a[i][j] != 0)
				v.push_back({ i, j });
		}
	}

	solve(0, a);

	cout << ret;

	return 0;
}