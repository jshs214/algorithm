#include <bits/stdc++.h>
using namespace std;

const int max_n = 304;
char dist[max_n][max_n];
int visited[max_n][max_n];

int startY, startX, destinationY, destinationX;
int n, m;	// m : y, n : x
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

bool flag = false;

int main() {
	cin >> m >> n;

	cin >> startY >> startX >> destinationY >> destinationX;
	
	for (int i = 1; i <= m; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= n; j++) {
			dist[i][j] = s[j - 1];
		}
	}

	fill(&visited[0][0], &visited[0][0] + max_n * max_n, 0);
	
	queue<pair<int, int>> q;
	visited[startY][startX] = 1;
	q.push({ startY, startX });

	int cnt = 0;
	while ( !visited[destinationY][destinationX]) {
		
		queue<pair<int, int>> temp;
		cnt++;

		while (q.size()) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny <1 || ny > m || nx<1 || nx >n) continue;
				if (visited[ny][nx]) continue;

				visited[ny][nx] = cnt;
				if (dist[ny][nx] != '0') {
					dist[ny][nx] = '0';
					temp.push({ ny,nx });
				}
				else
					q.push({ ny,nx });
			}
		}
		q = temp;
	}


	cout << visited[destinationY][destinationX];



	return 0;
}