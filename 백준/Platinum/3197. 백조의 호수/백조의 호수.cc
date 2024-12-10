#include <bits/stdc++.h>
using namespace std;

int r, c;
char a[1504][1504];
int visited[1504][1504];
int visitedSwan[1504][1504];

queue<pair<int, int> > swanQ;
queue<pair<int, int> > swan_tempQ;
queue<pair<int, int> > waterQ;
queue<pair<int, int> > water_tempQ;
vector<int> q;

int dy[] = { -1, 0, 1,0 };
int dx[] = { 0, -1, 0, 1 };

void Qclear(queue<pair<int, int>>& q) {
	queue<pair<int, int>> copy;
	swap(q, copy);
}

bool moveSwan() {
	while (swanQ.size()) {
		int y = swanQ.front().first;
		int x = swanQ.front().second;
		swanQ.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= r || nx >= c)continue;
			if (visitedSwan[ny][nx]) continue;
			visitedSwan[ny][nx] = 1;
			if (a[ny][nx] == '.') swanQ.push({ ny,nx });
			else if (a[ny][nx] == 'X') swan_tempQ.push({ ny,nx });
			else if (a[ny][nx] == 'L') return true;
		}
	}
	return false;
}

void waterMelting()
{
	while (waterQ.size()) {
		int y = waterQ.front().first;
		int x = waterQ.front().second;
		waterQ.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
			if (visited[ny][nx]) continue;

			if (a[ny][nx] == 'X') {
				visited[ny][nx] == 1;
				water_tempQ.push({ ny,nx });
				a[ny][nx] = '.';
			}

		}

	}
}

int main() {
	cin >> r >> c;

	int swanY; int swanX;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'L') {
				swanY = i;
				swanX = j;
			}
				
			if (a[i][j] == '.' || a[i][j] == 'L') {
				visited[i][j] = 1;
				waterQ.push({ i,j });
			}
		}
	}
	
	swanQ.push({ swanY, swanX });
	visitedSwan[swanY][swanX] = 1;

	int cnt = 0;

	while (true) {
		if (moveSwan()) break;
		waterMelting();
		waterQ = water_tempQ;
		swanQ = swan_tempQ;
		Qclear(water_tempQ);
		Qclear(swan_tempQ);

		cnt++;
	}

	cout << cnt;
	

	
	return 0;
}