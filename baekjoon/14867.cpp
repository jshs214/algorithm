#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;

map<pair<int, int>, int> m;

// a, b 물통 상황
queue<pair<int, int>> q;

void enqueue(int x, int y, int cnt) {
	// 옮겼을때 물통 상태가 있으면
	if (m[{x, y}]) return;

	m[{x, y}] = cnt + 1;
	q.push({ x,y });
}

int bfs(int x, int y) {
	m[{x, y}] = 1;
	q.push({ x,y });

	while (q.size()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		//fill
		enqueue(x, b, m[{x, y}]);
		enqueue(a, y, m[{x, y}]);
		// empty
		enqueue(x, 0, m[{x, y}]);
		enqueue(0, y, m[{x, y}]);
		// move
		enqueue(min(x + y, a), max(0, x + y - a), m[{x, y}]);
		enqueue(max(0, x + y - b), min(x + y, b), m[{x, y}]);
	}

	if (m[{c, d}]) return m[{c, d}] - 1;
	else return -1;

}

int main() {
	cin >> a >> b >> c >> d;

	cout << bfs(0, 0);
	return 0;
}