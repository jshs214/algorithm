#include <bits/stdc++.h>
using namespace std;

int n;
int a[22][22];

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

int ret;

void rotate(int board[22][22]) {
	int temp[22][22] = { 0, };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp[i][j] = board[n - j - 1][i];
		}
	}
	memcpy(board, temp, sizeof(temp));
}
void slide(int board[22][22]) {
	int temp[22][22] = { 0, };
	for (int i = 0; i < n; i++) {
		int cnt = 0;

		for (int j = 0; j < n; j++) {
			if (board[i][j] == 0) continue;
			if (temp[i][cnt] == 0)
				temp[i][cnt] = board[i][j];
			else if (temp[i][cnt] == board[i][j]) {
				temp[i][cnt] *= 2;
				cnt++;
			}
			else {
				cnt++;
				temp[i][cnt] = board[i][j];
			}
		}
	}

	memcpy(board, temp, sizeof(temp));
}

void game(int here, int board[22][22]) {
	if (here == 5) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cnt = max(cnt, board[i][j]);
			}
		}
		ret = max(ret, cnt);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int temp[22][22];
		memcpy(temp, board, sizeof(temp));
		slide(temp);
		game(here + 1, temp);
		rotate(board);
	}


}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	game(0, a);

	cout << ret;

	return 0;
}