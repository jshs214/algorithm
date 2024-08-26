#include <bits/stdc++.h>
using namespace std;

int r, c;

const int INF = 987654321;

char a[1004][1004];

int fireVisited[1004][1004];
int visited[1004][1004];

int y, x;

int dy[] = { -1, 0, 1 ,0 };
int dx[] = { 0, -1, 0, 1 };

int ret;

int main() {
	cin >> r >> c;

	int startY, startX;	//user

	queue<pair<int, int>> q;

	fill(&fireVisited[0][0], &fireVisited[0][0] + 1004 * 1004, INF);

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'J') {
				startY = i;  startX = j;
			}
			if (a[i][j] == 'F') {
				fireVisited[i][j] = 1;
				q.push({ i,j });
			}
		}
	}

	// ºÒ
	while (q.size()) {
		tie(y, x) = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
			if (fireVisited[ny][nx] != INF || a[ny][nx] == '#') continue;

			fireVisited[ny][nx] = fireVisited[y][x] + 1;
			q.push({ ny,nx });
		}
	}
	

	//»ç¶÷
	visited[startY][startX] = 1;
	q.push({ startY, startX });
	while (q.size()) {
		tie(y, x) = q.front(); q.pop();

		if (y == r - 1 || x == c - 1 || y == 0 || x == 0) {
			ret = visited[y][x];
			break;
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
			if (visited[ny][nx] || a[ny][nx] == '#') continue;

			if (visited[y][x] + 1 >= fireVisited[ny][nx]) continue;
			
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny,nx });
			
		}
	}

	if (ret == 0) cout << "IMPOSSIBLE";
	else cout << ret;



	return 0;
}