#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;

char dist[1504][1504];
int swanVisited[1504][1504];
int meltVisited[1504][1504];

queue<pair<int, int>> swanQ;
queue<pair<int, int>> swanQ_temp;
queue<pair<int, int>> waterQ;
queue<pair<int, int>> waterQ_temp;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

int r, c;
int cnt = 0;

void Qclear(queue<pair<int, int>>& q) {
	queue<pair<int, int>> copy;
	swap(q, copy);
}
bool CanMeet() {
	while (swanQ.size()) {
		int y = swanQ.front().first;
		int x = swanQ.front().second;
		swanQ.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
			if (swanVisited[ny][nx]) continue;
			swanVisited[ny][nx] = 1;
			if (dist[ny][nx] == '.') swanQ.push({ ny,nx });
			else if (dist[ny][nx] == 'X') swanQ_temp.push({ ny,nx });
			else if (dist[ny][nx] == 'L') return true;
		}
	}
	return false;
}
void Melt() {
	while (waterQ.size()) {
		int y = waterQ.front().first;
		int x = waterQ.front().second;
		waterQ.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
			if (meltVisited[ny][nx]) continue;

			if (dist[ny][nx] == 'X') {
				meltVisited[ny][nx] = 1;
				waterQ_temp.push({ ny,nx });
				dist[ny][nx] = '.';
			}

		}
	}
}

int main() {
	cin >> r >> c;

	int swanY, swanX;
	for (int i = 0; i < r; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < c; j++) {
			dist[i][j] = s[j];
			if (dist[i][j] == 'L') {
				swanY = i;
				swanX = j;
			}
			if (dist[i][j] == '.' || dist[i][j] == 'L') {
				waterQ.push({ i,j });
			}
		}
	}

	swanQ.push({ swanY, swanX });
	swanVisited[swanY][swanX] = 1;

	while (true) {
		if (CanMeet()) break;
		Melt();
		waterQ = waterQ_temp;
		swanQ = swanQ_temp;

		Qclear(waterQ_temp);
		Qclear(swanQ_temp);
		cnt++;
	}

	cout << cnt;

	
	return 0;
}