#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;

int n, cur[104], sol[104];
//     idx, x, y, z, dir
int dp[104][10][10][10][2];

int rot(int x){
	return (x < 0) ? x + 10 : x % 10;
}

int solve(int idx, int x, int y, int z, int dir) {
	if (idx == n) return 0;

	int& ret = dp[idx][x][y][z][dir];
	if (ret != -1) return ret;

	// 좌물쇠 idx와 정답이 맞으면
	if (rot(x + cur[idx]) == rot(sol[idx]) ) {
		ret = min(solve(idx + 1, y, z, 0, 0), solve(idx + 1, y, z, 0, 1));
		return ret;
	}

	ret = INF;
	int _dir = dir ? 1 : -1;		//실제 회전 방향

	for (int i = 1; i <= 3; i++) {
		ret = min(ret, 1 + solve(idx, rot(x + i * _dir),
										y, z, dir));
		ret = min(ret, 1 + solve(idx, rot(x + i * _dir), rot(y + i * _dir),
										z, dir));
		ret = min(ret, 1 + solve(idx, rot(x + i * _dir), rot(y + i * _dir), rot(z + i * _dir),
										dir));
	}
	return ret;
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%1d", &cur[i]);
	for (int i = 0; i < n; i++)
		scanf("%1d", &sol[i]);

	memset(dp, -1, sizeof(dp));
	//fill(&dp[0][0][0][0][0], &dp[0][0][0][0][0] + 104 * 10 * 10 * 10 * 2, -1);

	cout << min(solve(0, 0, 0, 0, 1), solve(0, 0, 0, 0, 0));


	return 0;
}
