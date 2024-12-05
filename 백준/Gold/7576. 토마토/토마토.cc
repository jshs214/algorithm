#include <bits/stdc++.h>
using namespace std;
const int max_n = 1004;

vector<pair<int, int>> tomato;

int n, m;  // m : y, n : x
int ret = 0;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

int a[max_n][max_n], visited[max_n][max_n];

// 경계, 토마토 들어있는지 검사
bool canGo(int y, int x) {
    if (y < 0 || y >= m || x < 0 || x >= n) return false;
    if (a[y][x] == -1) return false;
    return true;
}

int main() {
    cin >> n >> m;

    bool exception = true;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) {
                tomato.push_back({ i, j });
            }
            else if (a[i][j] == 0) {
                exception = false;
            }
        }
    }

    if (exception) {
        cout << 0;
        return 0;
    }

    queue<pair<int, int>> q;
    for (auto i : tomato) {
        q.push({ i.first, i.second });
        visited[i.first][i.second] = 1;
    }

    while (q.size()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (!canGo(ny, nx)) continue;
            if (visited[ny][nx]) continue;
            if (a[ny][nx] == 0) {
                visited[ny][nx] = visited[y][x] + 1;
                ret = max(ret, visited[ny][nx]);
                q.push({ ny, nx });
            }
        }
    }

    // 익지 않은 토마토 확인
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 0 && visited[i][j] == 0) {
                cout << -1;
                return 0;
            }
        }
    }

    cout << ret - 1; 

    return 0;
}
