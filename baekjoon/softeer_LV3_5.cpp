#include<iostream>
#include <vector>

using namespace std;

int n, m;
vector<pair<int, int>> v;
int startY, startX, destinationY, destinationX;

int a[6][6];
int visited[6][6];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };
int ret = 0;

void Input() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int y, x;
    cin >> y >> x;
    y--; x--;
    startY = y; startX = x;
    for (int i = 1; i < m; i++) {
        cin >> y >> x;
        y--; x--;
        v.push_back({ y, x });
    }

    destinationY = v[v.size() - 1].first;
    destinationX = v[v.size() - 1].second;

    v.pop_back();
}

void dfs(int y, int x, int cnt, int idx) {
    visited[y][x] = cnt;

    if (visited[destinationY][destinationX] == m && cnt == m) {
#if 0
        cout << "find" << "\n";
        cout << "cnt : " << cnt << "\n";

        for (int z = 0; z < n; z++) {
            for (int zz = 0; zz < n; zz++) {
                cout << visited[z][zz] << " ";
            }
            cout << '\n';
        }
#endif
        ret++;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        if (visited[ny][nx]) continue;
        if (a[ny][nx] == 1) continue; //º®


        visited[ny][nx] = cnt;

        if (v[idx].first == ny && v[idx].second == nx) {
            dfs(ny, nx, cnt + 1, idx + 1);
        }
        else
            dfs(ny, nx, cnt, idx);

        visited[ny][nx] = 0;
    }
}

int main(int argc, char** argv)
{
    Input();

    //visited[startY][startX] = 1;
    dfs(startY, startX, 1, 0);

    cout << ret;

    return 0;
}