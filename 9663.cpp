#include <bits/stdc++.h>
using namespace std;

int visited[17][17];
int n, result =0;

//종료 인지 check
bool check(int y, int x) {
	if (y >= 0 && x >= 0 && y < n && x < n )
		return true;

	return false;
}

bool MoveQueen(int y, int x) {
	// width 방향, height 방향
	for (int i = 0; i < n; i++) {
		if (visited[y][i]) {
			return false;
		}
		if (visited[i][x]) {
			return false;
		}
	}

	//대각 방향
	for (int i = 0; i < n; i++) {
		// '/' 방향
		if (check(y + i, x - i) && visited[y + i][x - i]) {
			return false;
		}
		if (check(y - i, x + i) && visited[y - i][x + i]) {
			return false;
		}

		// '\' 방향
		if (check(y + i, x + i) && visited[y + i][x + i]) {
			return false;
		}
		if (check(y - i, x - i) && visited[y - i][x - i]) {
			return false;
		}

	}

	return true;
}

void FixQueen(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < n; i++) {
		visited[i][x] = 1;
		visited[y][i] = 1;
	}

	for (int i = 0; i < n; i++) {
		int ny, nx;
		// '/' 방향
		if (check(y + i, x - i)) {
			ny = y + i;
			nx = x - i;
			visited[ny][nx] = 1;
		}
		if (check(y - i, x + i)) {
			ny = y - i;
			nx = x + i;
			visited[ny][nx] = 1;
		}
		// '\' 방향
		if (check(y - i, x - i)) {
			ny = y - i;
			nx = x - i;
			visited[ny][nx] = 1;
		}
		if (check(y + i, x + i)) {
			ny = y + i;
			nx = x + i;
			visited[ny][nx] = 1;
		}
	}
}

void solve(int y) {
	if (y == n) {
		result++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (MoveQueen(y, i)) {
			visited[y][i] = 1; 
			solve(y + 1); 
			visited[y][i] = 0; 
		}
	}

}

int main() {
	cin >> n;

	solve(0);
	
	cout << result;
	

	return 0;
}