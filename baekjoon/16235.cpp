#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int A[14][14], yangbun[14][14];
vector<int> a[14][14];

int dieTree[14][14];

int dy[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void spring() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j].size() == 0) continue;

			//나무 나이 순 정렬
			sort(a[i][j].begin(), a[i][j].end());

			int die_tree = 0;
			vector<int> temp;
			for (auto tree : a[i][j]) {
				// 양분 먹어지면
				if (yangbun[i][j] >= tree) {
					yangbun[i][j] -= tree;
					temp.push_back(tree + 1);	// 나이+1 나무
				}
				// 못먹으면 죽은나무 처리
				else {
					dieTree[i][j] += tree / 2;
				}
			}
			a[i][j] = temp;
		}
	}
}

void summer() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dieTree[i][j] == 0) continue;
			
			yangbun[i][j] += dieTree[i][j];
			
			dieTree[i][j] = 0;
		}
	}
}

void fall() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j].size() == 0) continue;

			//나무 순회
			for (auto tree : a[i][j]) {
				if ( (tree % 5) == 0) {
					for (int k = 0; k < 8; k++) {
						int ny = i + dy[k];
						int nx = j + dx[k];

						if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
						a[ny][nx].push_back(1);
					}
				}
			}


		}
	}
}

void winter() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			yangbun[i][j] += A[i][j];
		}
	}
}

int main() {
	cin >> n >> m >> k;

	fill(&yangbun[0][0], &yangbun[0][0] + 14 * 14, 5);
	fill(&dieTree[0][0], &dieTree[0][0] + 14 * 14, 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
		}
	}
	
	for (int i = 0; i < m; i++) {
		int y, x, c;
		cin >> y >> x >> c;
		y--;
		x--;
		// 위치 별 나무 나이
		a[y][x].push_back(c);
	}

	for (int i = 0; i < k; i++) {
		spring();
		summer();
		fall();
		winter();
	}

	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ret += a[i][j].size();
		}
	}

	cout << ret;


	return 0;
}