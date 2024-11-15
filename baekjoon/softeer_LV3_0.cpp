#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int per[3] = { 0, 1, 2 };
int n, m;
vector<pair<int, int>> v;
int a[24][24];
int copyVisited[24][24];
int visited[24][24];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

vector<pair<int, int>> path;
vector<pair<int, int>> best_path;
int max_value = 0;
int result = 0;
int ret = 0;

bool check(int y, int x) {
    return (y >= 0 && y < n && x >= 0 && x < n);
}

int solve(int y, int x, int cnt, int value) {
    if (cnt == 3) {
        if (value > max_value) {
            max_value = value;
            best_path = path;
        }
        return max_value;
    }

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (!check(ny, nx) || visited[ny][nx]) continue;

        visited[ny][nx] = 1;
        path.push_back({ ny, nx });

        max_value = max(max_value, solve(ny, nx, cnt + 1, value + a[ny][nx]));

        visited[ny][nx] = 0;
        path.pop_back();
    }

    return max_value;
}

// 순열 기반 탐색
void makePermutation(int depth, int r) {
    if (depth == r) {
        memcpy(visited, copyVisited, sizeof(visited)); // 초기화
        result = 0;

        for (int i = 0; i < m; i++) {
            int y = v[per[i]].first;
            int x = v[per[i]].second;
            int val = a[y][x];

            max_value = 0;
            path.clear();
            result += solve(y, x, 0, val);

            for (auto& p : best_path) {
                visited[p.first][p.second] = 1;
            }

            best_path.clear();
            path.clear();
        }
        ret = max(ret, result);

        return;
    }

    for (int i = depth; i < m; i++) {
        swap(per[depth], per[i]);
        makePermutation(depth + 1, r);
        swap(per[depth], per[i]);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        int y, x;
        cin >> y >> x;
        y--; x--;
        v.push_back({ y, x });
        visited[y][x] = 1;
    }

    memcpy(copyVisited, visited, sizeof(visited));

    makePermutation(0, m);

    cout << ret;

    return 0;
}
