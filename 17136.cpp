#include <bits/stdc++.h>

using namespace std;

#define N 10
#define INF 987654321
int ret = INF;

int a[12][12];

// 1x1 ~ 5x5 »öÁ¾ÀÌ
map<int, int> mp; 

bool check(int y, int x, int can) {
	if (y + can > N || x + can > N) return false;

	for (int i = y; i < y + can; i++) {
		for (int j = x; j < x + can; j++) {
			if (a[i][j] == 0) return false;
		}
	}
	return true;

}

void draw(int y, int x, int can, int value) {
	for (int i = y; i < y + can; i++) {
		for (int j = x; j < x + can; j++) {
			a[i][j] = value;
		}
	}
}

void dfs(int y, int x, int cnt) {
	if (cnt >= ret)
		return;
	if (x == N) {
		dfs(y + 1, 0, cnt);
		return;
	}
	if (y == N) {
		ret = min(ret, cnt);
		return;
	}

	if (a[y][x] == 0) {
		dfs(y, x + 1, cnt);
		return;
	}


	for (int size = 5; size >= 1; size--) {
		//if (mp[size] == 5) continue;
		if (check(y, x, size)) {
			mp[size]++;
			draw(y, x, size, 0);
			dfs(y, x, cnt + 1);
			draw(y, x, size, 1);
			mp[size]--;
		}
	}
}

int main() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
		}
	}
	dfs(0, 0, 0);

	cout << (ret == INF ? -1 : ret);
	return 0;
}