#include <bits/stdc++.h>
using namespace std;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

int n, m, ret;

int a[101][101];
bool visited[101][101];

void PrintA() {
	cout << "------------------------------------" << "\n";
	cout << "Map arr" << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}
void PrintVisited() {
	cout << "------------------------------------" << "\n";
	cout << " Visited Arr" << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}
}

// 사분면 탐색 후 0이면 visited
void dfs(int y, int x) {
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny >= n || nx >= m || ny < 0 || nx < 0)	continue;

		if (!visited[ny][nx] && a[ny][nx] == 0)
			dfs(ny, nx);
	}

	return;
}

void clearCheese(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny >= n || nx >= m || ny < 0 || nx < 0)	continue;

		if (visited[ny][nx] == 0)
			a[ny][nx] = 0;
	}

	return;

}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 1) ret++;
		}
	}

	int cnt = 0;

	int test;
	while (ret > 0) {
		test = ret;
		// logic
		memset(visited, 0, sizeof(bool) * 100 * 100);
		dfs(0, 0);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visited[i][j] == 1)
					clearCheese(i, j);
			}
		}

		// make ret
		int cheeseCnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 1) cheeseCnt++;
			}
		}
		ret = cheeseCnt;

		cnt++;

	}

	cout << cnt << "\n";
	cout << test << "\n";
	


	return 0;
}
