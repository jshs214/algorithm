#include <bits/stdc++.h>
using namespace std;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

int a[102][102];
int visited[102][102];

int ret =0, n;

int mxHeight =0;

void dfs(int y, int x, int height) {
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (!visited[ny][nx] && a[ny][nx] > height)
			dfs(ny, nx, height);

	}

	return;
}


int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			mxHeight = max(mxHeight, a[i][j]);
		}
	}


	//높이 max까지 반복
	for (int k = 1; k <= mxHeight; k++) {
		memset(visited, 0, sizeof(visited));
		
		int cnt = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j] && a[i][j] > k) {
					dfs(i, j, k);
					cnt++;
				}
			}
		}

		ret = max(ret, cnt);
	}

	if (ret != 0)
		cout << ret;
	else cout << "1";
	

	return 0;
}