
// 3번째 테케 확인.
// 사과 이후 꼬리처리 확인

#include <bits/stdc++.h>
using namespace std;

int a[104][104] = { 0, };
int visited[104][104];
int n, k, l;

int ret = 0;

deque<pair<int, int>> snake;

// 1 ~ 4
int direction = 0; // 초기 방향: 오른쪽
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

// direction rotate
void rotate(char c) {
	if (c == 'D')
		direction = (direction + 1) % 4;
	else if (c == 'L')
		direction = (direction + 3) % 4;
}

bool move() {
	//snake
	int y = snake.front().first;
	int x = snake.front().second;

	int ny = y + dy[direction];
	int nx = x + dx[direction];

	if (ny < 0 || nx < 0 || ny >= n || nx >= n || a[ny][nx] ==1) {
		return false;
	}
		
	if (a[ny][nx] == 2) {
		a[ny][nx] = 1;
		snake.push_front({ ny,nx });
	}
	else {
		a[ny][nx] = 1;
		snake.push_front({ ny,nx });
			
		//꼬리 처리
		a[snake.back().first][snake.back().second] = 0;
		snake.pop_back();
	}

	return true;
}


int main() {
	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		int y, x;
		cin >> y >> x;
		
		a[y][x] = 2;
	}

	cin >> l;
	

	// 뱀 시작
	snake.push_back({ 0,0 });
	a[0][0] = 1;

	// 사과
	vector<pair<int, char>> p;
	for (int i = 0; i < l; i++) {
		int x;
		char c;

		cin >> x >> c;
		p.push_back({ x, c });
	}

	int turn_idx = 0;
	while (true) {
		if (turn_idx < p.size() && ret == p[turn_idx].first) {
			rotate(p[turn_idx].second);
			turn_idx++;
		}

		// 1초 이동
		if (!move()) {
			break;
		}

		ret++;
	}


	

	cout << ret +1;



	return 0;
}