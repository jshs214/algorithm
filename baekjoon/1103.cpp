#include <bits/stdc++.h>
using namespace std;


char dist[54][54];
bool visited[54][54];
int dp[54][54];

string s;
int n, m, ret;
int dy[] = { -1, 0 , 1, 0 };
int dx[] = { 0, -1, 0, 1 };

bool overflow(int y, int x) {
	return(1 <= y && y <= n && 1 <= x && x <= m);
}

int go(int y, int x) {
	if ( !overflow(y,x) || dist[y][x] == 'H')
		return 0;
	

	if (visited[y][x]) {
		cout << "-1";
		exit(0);
	}

	int& ret = dp[y][x];
	if (ret) return ret;

	visited[y][x] = 1;
	int value = (int)dist[y][x] - '0';
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i] * value;
		int nx = x + dx[i] * value;
		ret = max(ret, go(ny, nx)+1 );
	}
	visited[y][x] = 0;

	return ret;
}

int main() {

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		for (int j = 1; j <= m; j++) {
			dist[i][j] = s[j - 1];
		}
	}

	cout << go(1, 1);

	return 0;
}