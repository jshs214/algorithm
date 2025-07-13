#include <bits/stdc++.h>

using namespace std;

const int max_n = 12;

int n;
int a[max_n][max_n];
int visited[max_n][max_n];
int ret = 987654321;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

int setFlower(int y, int x)
{
	visited[y][x] = 1;

	int sum = a[y][x];
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		visited[ny][nx] = 1;
		sum += a[ny][nx];
	}
	return sum;
}
void eraseFlower(int y, int x)
{
	visited[y][x] = 0;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		visited[ny][nx] = 0;
	}
}

bool check(int y, int x)
{
	if (visited[y][x]) return false;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) return false;
		if (visited[ny][nx]) return false;
	}
	return true;
}

void go(int cnt, int cost)
{
	if (cnt == 3) {
		ret = min(ret, cost);
		return;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (check(i, j)) {
				go(cnt + 1, cost + setFlower(i, j));
				eraseFlower(i, j);
			}

		}
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	
	go(0, 0);
		
	cout << ret;
	return 0;
}