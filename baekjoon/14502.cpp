#include <bits/stdc++.h>
using namespace std;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

int n, m;
int ret;

int arr[10][10];
bool visited[10][10];

vector<pair<int, int>> virus, wall;

void dfs(int y, int x) {
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny >= n || nx >= m || ny < 0 || nx < 0 || visited[ny][nx])	continue;
		if (arr[ny][nx] == 0)
			dfs(ny, nx);
	}

	return;
}

void Combi(int start, vector<int> b) {
	if (b.size() == 3) {
		for (auto i : b)
			arr[wall[i].first][wall[i].second] = 1;



		memset(visited, 0, sizeof(bool) * 10 * 10);

		//logic [start]
		for (auto i : virus) {
			visited[i.first][i.second] = 1;
			dfs(i.first, i.second);
		}


		int cnt =0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 0 && !visited[i][j]) {
					cnt++;
				}
			}
		}
		ret = max(ret, cnt);
		//logic [end]



		for (auto i : b)
			arr[wall[i].first][wall[i].second] = 0;


		return;
	}

	for (int i = start + 1; i < wall.size(); i++) {
		b.push_back(i);
		Combi(i, b);
		b.pop_back();
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 2)	virus.push_back({ i,j } );
			if (arr[i][j] == 0) wall.push_back({ i, j } );
		}
	}

	vector<int> b;
	Combi(-1, b);


	cout << ret << "\n";

	return 0;
}



#if 0
#include <bits/stdc++.h>
using namespace std;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

int ny, nx, n, m, ret;
int wallLen;

int arr[10][10];
bool visited[10][10];

vector<pair<int, int>> virusList;
vector<pair<int, int>> wallList;


void dfs(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		ny = y + dy[i];
		nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (arr[ny][nx] == 0 && !visited[ny][nx]) {
			dfs(ny, nx);
		}

	}
	return;
}

int Calldfs() {
	fill(&visited[0][0], &visited[0][0] + 10 * 10, 0);

	//virus 확장
	for (auto i : virusList) {
		visited[i.first][i.second] = 1;
		dfs(i.first, i.second);
	}

	//남은 청정 영역 카운트
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0 && !visited[i][j]) {
				cnt++;
			}
		}
	}
	return cnt;
}

void Combi(int start, vector<int> b) {
	if (b.size() == 3) {

		for (auto i : b)
			arr[wallList[i].first][wallList[i].second] = 1;

		ret = max(ret, Calldfs());

		for (auto i : b)
			arr[wallList[i].first][wallList[i].second] = 0;

		return;
	}
	for (int i = start + 1; i < wallList.size(); i++) {
		b.push_back(i);
		Combi(i, b);
		b.pop_back();
	}

}



int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) virusList.push_back({ i, j });
			if (arr[i][j] == 0) wallList.push_back({ i, j });
		}
	}

	vector<int> b;
	Combi(-1, b);

	cout << ret << "\n";



	return 0;
}
#endif