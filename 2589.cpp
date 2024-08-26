#include<bits/stdc++.h>
using namespace std;

int dy[] = { -1, 0, 1 ,0 };
int dx[] = { 0, -1, 0 , 1 };
int ret = 0;

char a[55][55];
int visited[55][55];

vector<pair<int, int>> v;

int n, m;

struct coord {
	int y;
	int x;
};

void bfs(int y, int x) {
	memset(visited, 0, sizeof(visited));
	visited[y][x] = 1;

	queue<coord> q;
	q.push({ y, x });
	while (q.size()) {
		coord c = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = c.y + dy[i];
			int nx = c.x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

			if (!visited[ny][nx] && a[ny][nx] == 'L') {
				visited[ny][nx] = visited[c.y][c.x] + 1;
				q.push({ ny, nx });
				ret = max(ret, visited[ny][nx]);

			}

		}
	}

	return;
}


int main() {
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'L')
				v.push_back({ i, j } );
		}
	}


	for ( pair<int, int> i : v) 
		bfs(i.first, i.second);
	

	cout << ret-1;



	return 0;
}