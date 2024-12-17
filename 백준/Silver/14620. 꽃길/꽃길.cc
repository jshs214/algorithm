#include <bits/stdc++.h>
using namespace std;

int a[14][14];
int visited[14][14];
int n;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0 , 1 };
int minCost = INT_MAX;

bool CanFlower(int y, int x) {
	if (visited[y][x]) return false;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n) return false;
		if (visited[ny][nx]) return false;
	}

	return true;
}
int getCost(int y, int x) {
	int cost = a[y][x];

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		cost += a[ny][nx];
	}
	return cost;
}
void Visit(int y, int x, int flag) {
	visited[y][x] = flag;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		visited[ny][nx] = flag;
	}
}

void go(int here, int cost) {
	if (here == 3) {
		minCost = min(minCost, cost);
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!CanFlower(i, j)) continue;
			Visit(i, j, 1);
			int _cost = cost + getCost(i, j);
			go(here + 1, _cost);
			Visit(i, j, 0);
		}
	}
}


int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	go(0, 0);

	cout << minCost;

	return 0;
}