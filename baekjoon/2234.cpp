#include "bits/stdc++.h"
using namespace std;

int a[55][55];
int visited[55][55];
int n, m;

int cnt=0;
int countArr[2504];

int ret1, ret2, ret3;

int dx[] = {-1, 0, 1, 0 };
int dy[] = {0, -1, 0, 1 };

void Print(int s);

int dfs(int y, int x, int count) {
	if (visited[y][x]) return 0;
	visited[y][x] = count;
	int ret = 1;

	for (int i = 0; i < 4; i++) {	
		// (º® case) !¿¬»ê 
		if (!( a[y][x] & (1 << i))  ) {
			int ny = dy[i] + y;
			int nx = dx[i] + x;
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			ret += dfs(ny, nx, count);
		}
	}

	return ret;
}

int main() {
	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j]) {
				cnt++;
				countArr[cnt] = dfs(i, j, cnt);
				ret2 = max(ret2, countArr[cnt]);
			}
		}
	}
	ret1 = cnt;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i + 1 < n) {
				int one = visited[i][j];
				int two = visited[i + 1][j];
				if (one != two) {
					ret3 = max(ret3 , countArr[one] + countArr[two]);
				}
			}

			if (j + 1 < m) {
				int one = visited[i][j];
				int two = visited[i][j+1];
				if (one != two) {
					ret3 = max(ret3, countArr[one] + countArr[two]);
				}
			}
		}
	}


	cout << ret1 << "\n";
	cout << ret2 << '\n';
	cout << ret3 ;



	return 0;
}
