#include <bits/stdc++.h>
using namespace std;

int dy[] = { 0, -1, 0, 1 };
int dx[] = { 1, 0, -1, 0 };

int a[104][104];

int x, y, d, g, n;

void move(int &y, int &x, int dir) {
	int ny = y + dy[dir];
	int nx = x + dx[dir];

	if (ny < 0 || nx < 0 || ny >= 104 || nx >= 104) return;

	y = ny;
	x = nx;
	a[y][x] = 1;  // 해당 위치에 드래곤 커브 표시
}

void generateDragonCurve() {
	vector<int> directions;

	// 0세대
	a[y][x] = 1;
	directions.push_back(d);
	move(y, x, d);

	// 1~g세대
	for (int i = 1; i <= g; i++) {
		int size = directions.size();

		for (int j = size - 1; j >= 0; j--) {
			int newDir = (directions[j] + 1) % 4;
			move(y, x, newDir);
			directions.push_back(newDir);
		}
	}
}



int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x >> y >> d >> g;
		generateDragonCurve();
	}

	// rect count
	int ret = 0;
	for (int i = 0; i < 104-1; i++) {
		for (int j = 0; j < 104-1; j++) {
			if (a[i][j] == 1 && a[i][j + 1] == 1 &&
				a[i + 1][j] == 1 && a[i + 1][j + 1] == 1)
				ret++;
		}
	}

	cout << ret;

	return 0;
}