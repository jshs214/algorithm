//#include <bits/stdc++.h>
//using namespace std;
//
//int n;
//
//int scv[3];
//int ret =0;
//
//bool check() {
//
//	for (int i = 0; i < n; i++) {
//		if (scv[i] > 0)
//			return false;
//	}
//
//
//	return true;
//}
//
//int main() {
//	cin >> n;
//
//	for (int i = 0; i < n; i++) {
//		cin >> scv[i];
//	}
//
//
//	while (!check()) {
//		sort(scv, scv + n, greater<int>());
//
//		if (n == 3) {
//			scv[0] -= 9;
//			scv[1] -= 3;
//			scv[2] -= 1;
//		}
//		else if (n== 2) {
//			scv[0] -= 9;
//			scv[1] -= 3;
//		}
//		else if (n== 1) {
//			scv[0] -= 9;
//		}
//
//		ret++;
//
//		//cout << ret << "         :  " << scv[0] << ", " << scv[1] << ", " << scv[2] << "\n";
//	}
//	cout << ret;
//
//
//	return 0;
//}

#include <bits/stdc++.h>
using namespace std;

int n;

int attack[6][3] = {
	{9, 3, 1},
	{9, 1, 3},
	{1, 3, 9},
	{1, 9, 3},
	{3, 9, 1},
	{3, 1, 9}
};

int visited[64][64][64];
int scv[3];

struct A {
	int a, b, c;
};

queue<A> q;

int bfs(int a, int b, int c) {
	visited[a][b][c] = 1;
	q.push({a,b,c});

	while (q.size()) {
		int a = q.front().a;
		int b = q.front().b;
		int c = q.front().c;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int na = max( 0, a - attack[i][0]);
			int nb = max(0, b - attack[i][1]);
			int nc = max(0, c - attack[i][2]);

			if (visited[na][nb][nc]) continue;
			visited[na][nb][nc] = visited[a][b][c] + 1;
			q.push({ na,nb,nc });
		}

	}
	return visited[0][0][0] - 1;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> scv[i];
	}
	cout << bfs(scv[0], scv[1], scv[2]);
	
	
	return 0;
}