#include <bits/stdc++.h>

using namespace std;

#define horizontal 0	//가로
#define vertical 1		//세로
#define diagonal 2		//대각

int dist[20][20];
int dp[20][20][3];
int n;
int cnt = 0;

// status 
int in(int y, int x) {
	return (1 <= y && y <= n && 1 <= x && x <= n);
}

// DP
int solve(int y, int x, int status) {
    if (y == n && x == n) return 1;
    if (!in(y, x) || dist[y][x] == 1) return 0;

    int& ret = dp[y][x][status];
    if (ret != -1) return ret;

    ret = 0;

    if (status == horizontal) {
        if (dist[y][x + 1] == 0) 
            ret += solve(y, x + 1, horizontal);
        if (dist[y + 1][x + 1] == 0) 
            ret += solve(y + 1, x + 1, diagonal);
    }

    if (status == vertical) {
        if (dist[y + 1][x] == 0)
            ret += solve(y + 1, x, vertical);
        if (dist[y + 1][x + 1] == 0)
            ret += solve(y + 1, x + 1, diagonal);
    }

    if (status == diagonal) {
        if (dist[y][x + 1] == 0)
            ret += solve(y, x + 1, horizontal);
        if (dist[y + 1][x] == 0)
            ret += solve(y + 1, x, vertical);
        if (dist[y + 1][x + 1] == 0) 
            ret += solve(y + 1, x + 1, diagonal);
    }

    return ret;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> dist[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));
	
	cout << solve(1, 2, horizontal);


	return 0;
}