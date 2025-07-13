#include <bits/stdc++.h>
using namespace std;

char a[22][22];
int visited_Alph[26];
int r, c;
int ret = -987654321;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };


void dfs(int y, int x, int count) {
	ret = max(ret, count);

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;

		int next = (int)(a[ny][nx] - 'A');

		if (visited_Alph[next] == 0) {
			visited_Alph[next] = 1;
			dfs(ny, nx, count + 1);
			visited_Alph[next] = 0;
		}
	}
	return;
}


int main() {
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
		}
	}

	visited_Alph[(int)a[0][0] - 'A'] = 1;
	dfs(0, 0, 1);

	cout << ret;


	return 0;
}