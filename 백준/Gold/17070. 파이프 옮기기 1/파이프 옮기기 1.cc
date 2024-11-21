#include <bits/stdc++.h>
using namespace std;

#define horizontal 1
#define vertical 2
#define cross 3
#define maxN 16
int n;
int dist[maxN][maxN];
int dp[maxN][maxN][3];


int solve(int y, int x, int dir) {
	if (y == n - 1 && x == n - 1) {
		if (dist[y][x] == 1) return 0;

		return 1;
	}

	int& ret = dp[y][x][dir];
	if (ret != -1) return ret;

	ret = 0;


	if (x + 1 < n && y + 1 < n && dist[y + 1][x] != 1 && dist[y][x + 1] != 1 && dist[y + 1][x + 1] != 1)
		ret += solve(y + 1, x + 1, cross);

	if (dir == horizontal) {
		if (x + 1 < n && dist[y][x+1] != 1)
			ret += solve(y, x + 1, horizontal);
	}else if (dir == vertical) {
		if (y + 1 < n && dist[y+1][x] != 1)
			ret += solve(y +1, x, vertical);
	}else if (dir == cross) {
		if (x + 1 < n && dist[y][x + 1] != 1)
			ret += solve(y, x + 1, horizontal);
		if (y + 1 < n && dist[y + 1][x] != 1)
			ret += solve(y + 1, x, vertical);
	}
		 
	return ret;
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> dist[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));
	
	cout << solve(0, 1, horizontal);
	

	return 0;
}